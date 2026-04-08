#!/bin/bash

# Si algo falla, el script se detiene
set -e

echo "Starting MariaDB database setup..."

# 1. Cargar contraseñas desde los secrets
if [ -f "$MYSQL_ROOT_PASSWORD_FILE" ]; then
    MYSQL_ROOT_PASSWORD=$(cat "$MYSQL_ROOT_PASSWORD_FILE")
fi
if [ -f "$MYSQL_PASSWORD_FILE" ]; then
    MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
fi

# 2. Solo inicializamos y configuramos si la base de datos NO existe todavía
# Comprobamos si existe la carpeta de nuestra base de datos específica
if [ ! -d "/var/lib/mysql/${MYSQL_DATABASE}" ]; then
    echo "First run: Initializing data directory and users..."
    
    # Inicializar el sistema de archivos de MariaDB
    mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null

    # Arrancar servidor temporal para configurar usuarios
    mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking --socket=/run/mysqld/mysqld.sock &
    pid="$!"

    # Esperar a que el servidor temporal responda
    echo "Waiting for temporary MariaDB..."
    until mysqladmin --socket=/run/mysqld/mysqld.sock ping >/dev/null 2>&1; do
        sleep 1
    done

    # Configurar usuarios y base de datos
    echo "Running setup SQL..."
    mysql --socket=/run/mysqld/mysqld.sock -u root << EOF
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

    # Apagar el servidor temporal
    echo "Shutting down temporary MariaDB..."
    mysqladmin --socket=/run/mysqld/mysqld.sock -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
    wait "$pid"
    
    echo "Setup finished successfully."
else
    echo "Database already exists in volume, skipping initialization."
fi

# 3. Ejecución final del servicio para producción
echo "Starting MariaDB for production..."
exec mysqld --user=mysql --datadir=/var/lib/mysql --bind-address=0.0.0.0