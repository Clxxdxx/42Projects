#!/bin/bash

set -e

cd /var/www/html

if [ -f "$WORDPRESS_DB_PASSWORD_FILE" ]; then
    WORDPRESS_DB_PASSWORD=$(cat "$WORDPRESS_DB_PASSWORD_FILE")
    export WORDPRESS_DB_PASSWORD
fi

echo "Setting up WordPress..."

# Descarga solo si no hay archivos
if [ ! -f "wp-includes/version.php" ]; then
    echo "Downloading WordPress..."
    wp core download --allow-root --path=/var/www/html
fi

# PRIMERO esperar a MariaDB, LUEGO crear config
echo "Waiting for MariaDB to be ready..."
until mysqladmin ping -h"$WORDPRESS_DB_HOST" -u"$WORDPRESS_DB_USER" -p"$WORDPRESS_DB_PASSWORD" --silent 2>/dev/null; do
    echo "MariaDB is not ready yet... sleeping 2s"
    sleep 2
done
echo "MariaDB is ready!"

# Crear config solo si no existe, y con --skip-check para no depender de la conexión
if [ ! -f "wp-config.php" ]; then
    echo "Creating wp-config.php..."
    wp config create --allow-root \
        --dbname=$WORDPRESS_DB_NAME \
        --dbuser=$WORDPRESS_DB_USER \
        --dbpass=$WORDPRESS_DB_PASSWORD \
        --dbhost=$WORDPRESS_DB_HOST \
        --path=/var/www/html \
        --skip-check \
        --force
fi

# Instalar solo si no está instalado
if ! wp core is-installed --allow-root; then
    echo "Installing WordPress database..."
    wp core install \
        --url=${DOMAIN_NAME} \
        --title="Inception clalopez" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --skip-email \
        --allow-root

    echo "Creating second user..."
    wp user create ${WP_USER} ${WP_USER_EMAIL} \
        --role=author \
        --user_pass=${WP_USER_PASSWORD} \
        --allow-root
else
    echo "WordPress already installed."
fi

chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

echo "Starting PHP-FPM..."
mkdir -p /run/php
exec php-fpm8.2 -F