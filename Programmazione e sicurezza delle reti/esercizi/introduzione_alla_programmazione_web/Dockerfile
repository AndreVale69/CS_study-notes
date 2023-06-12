FROM python:3.8-slim-buster

WORKDIR /python-docker

RUN pip3 install flask

COPY server.py server.py

CMD [ "python3", "server.py"]