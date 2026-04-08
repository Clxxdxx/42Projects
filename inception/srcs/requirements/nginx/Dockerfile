ARG DEB_VERSION="bookworm-slim"

FROM debian:${DEB_VERSION}

#install nginx and openssl
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

#change id www-data to avoid permissions problems between system and container
RUN usermod -u 33 www-data && groupmod -g 33 www-data

#create directory for ssl
RUN mkdir -p /etc/nginx/ssl

#copy config files
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/generate_ssl.sh /usr/local/bin/

#set permissions
RUN chmod +x /usr/local/bin/*.sh

#port 443(https standard)
EXPOSE 443

ENTRYPOINT ["/usr/local/bin/generate_ssl.sh"]