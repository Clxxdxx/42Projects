#!/bin/bash

#if script failure, close
set -e

#create directory to ssl
mkdir -p /etc/nginx/ssl

#set default domain name
: "${DOMAIN_NAME:=localhost}"

#if not exists, generate certificate ssl
if [ ! -f /etc/nginx/ssl/nginx.crt ]; then
    echo "Generating self-signed SSL certificate for ${DOMAIN_NAME}"

    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/nginx.key \
        -out /etc/nginx/ssl/nginx.crt \
        -subj "/C=US/ST=State/L=City/O=Organization/CN=${DOMAIN_NAME}"

    chmod 600 /etc/nginx/ssl/nginx.key
    chmod 644 /etc/nginx/ssl/nginx.crt

    echo "SSL certificate generated at /etc/nginx/ssl/"
else
    echo "SSL certificate already exists. See /etc/nginx/ssl/"
fi

#test nginx configuration
echo "Testing nginx configuration"
nginx -t
echo "Nginx configuration test passed."

#start nginx
echo "Starting Nginx"
exec nginx -g "daemon off;"