FROM ubuntu:trusty
MAINTAINER linuxhint
RUN apt-get update \
	&& apt-get install dialog apt-utils -y \
	&& apt-get install -y nginx \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* 
#	&& echo "daemon off;" >> /etc/nginx/nginx.conf

CMD nginx -g "daemon off;"
#ADD src/ /usr/share/nginx/html

FROM nginx:latest
COPY ./index.html /usr/share/nginx/html/index.html

EXPOSE 8080
CMD service nginx start
