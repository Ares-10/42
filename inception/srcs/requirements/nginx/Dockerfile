FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install nginx openssl

COPY ./tools/script.sh /script.sh

RUN chmod +x /script.sh

CMD ["/script.sh"]