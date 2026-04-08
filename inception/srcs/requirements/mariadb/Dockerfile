ARG DEB_VERSION="bookworm-slim"

FROM debian:${DEB_VERSION}

#install MariaDB
RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

#create directoris
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld \
    && mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql

#copy configuration
COPY conf/50-server.conf /etc/mysql/mariadb.conf.d/
COPY tools/init_db.sh /usr/local/bin/

#permisions
RUN chmod +x /usr/local/bin/init_db.sh

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/init_db.sh"]