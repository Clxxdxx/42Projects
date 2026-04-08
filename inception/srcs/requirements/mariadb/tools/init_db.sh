#!/bin/bash

#if something fails, stop script
set -e

echo "Starting MariaDB database setup..."

#load passwords from secrets
if [ -f "$MYSQL_ROOT_PASSWORD_FILE" ]; then
    MYSQL_ROOT_PASSWORD=$(cat "$MYSQL_ROOT_PASSWORD_FILE")
fi
if [ -f "$MYSQL_PASSWORD_FILE" ]; then
    MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
fi

#only init and config if database don't exists
#check if folder exists
if [ ! -d "/var/lib/mysql/${MYSQL_DATABASE}" ]; then
    echo "First run: Initializing data directory and users..."
    
    #init MariaDB filesystem
    mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null

    #start temporal sever to config users
    mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking --socket=/run/mysqld/mysqld.sock &
    pid="$!"

    #wait to server response
    echo "Waiting for temporary MariaDB..."
    until mysqladmin --socket=/run/mysqld/mysqld.sock ping >/dev/null 2>&1; do
        sleep 1
    done

    #config users and database
    echo "Running setup SQL..."
    mysql --socket=/run/mysqld/mysqld.sock -u root << EOF
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

    #shuttig server
    echo "Shutting down temporary MariaDB..."
    mysqladmin --socket=/run/mysqld/mysqld.sock -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
    wait "$pid"
    
    echo "Setup finished successfully."
else
    echo "Database already exists in volume, skipping initialization."
fi

#exec service
echo "Starting MariaDB for production..."
exec mysqld --user=mysql --datadir=/var/lib/mysql --bind-address=0.0.0.0