FROM debian:buster

CMD docker run --name nginx -d -p 80:80 nginx
ADD ./index.html /usr/share/nginx/html

EXPOSE 80
CMD service nginx start
