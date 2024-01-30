FROM debian:bullseye

EXPOSE 9000

COPY ./tools/setup.sh /setup.sh

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y curl mariadb-client php7.4-fpm php-mysql && \
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin && \
    ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp-cli && \
    mkdir -p /var/www/html /run/php && \
    usermod -G www-data -a www-data && \
    chown -R www-data:www-data /var/www/ && \
    chmod +x setup.sh

WORKDIR /var/www/html

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

ENTRYPOINT ["sh", "/setup.sh"]