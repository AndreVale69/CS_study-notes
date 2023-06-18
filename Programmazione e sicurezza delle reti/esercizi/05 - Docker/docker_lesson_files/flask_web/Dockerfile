# Our image is built starting from the pre-built image Alpine:
# A minimal Docker image based on Alpine Linux
FROM alpine:latest

# installing Python and pip in Alpine
# with the keyword "ENV" we can set enviroment variables
ENV PYTHONBUFFERED=1
# using the command "RUN" we can execute shell commands while building an Image
RUN apk add --update --no-cache python3 py3-pip && ln -sf python3 /usr/bin/python
RUN python3 -m ensurepip
RUN pip3 install --no-cache --upgrade pip setuptools

# Using the COPY command we can copy files from the local filesystem to
# the image's one and vice-versa
COPY ./requirements.txt /app/requirements.txt

# setting the working directory
WORKDIR /app

RUN pip install -r requirements.txt

COPY . /app

# With the keyword ENTRYPOINT we can set an executable to be run
# when the container starts up
ENTRYPOINT ["python"]
# we can use the CMD command to specify arguments for the executable
CMD ["app.py"]
