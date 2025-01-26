#!/bin/bash

sleep 3

cp /wp-config.php /var/www/html/

cd /var/www/html/

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

chmod +x wp-cli.phar

mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root

wp user create ${WP_ADMIN_USER} ${WP_ADMIN_EMAIL} --role=author --user_pass=${WP_ADMIN_PWD} --allow-root

wp user create ${WP_USR} ${WP_EMAIL} --role=author --user_pass=${WP_PWD} --allow-root

sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 0.0.0.0:9000/g' /etc/php/7.4/fpm/pool.d/www.conf

sed -i 's/;clear_env = no/clear_env = no/g' /etc/php/7.4/fpm/pool.d/www.conf

mkdir -p /run/php

/usr/sbin/php-fpm7.4 -F