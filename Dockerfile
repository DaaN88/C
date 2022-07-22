FROM alpine:latest

ENV PYTHONUNBUFFERED=1

RUN apk update && apk add --no-cache \
    nano \
    vim \
    sudo \
	cmake \
    git \
    perl \
    unzip \
    tar \
    curl \
    build-base gcc g++ \
    libc-dev \
    boost-dev \
    boost-static \
	python3

RUN python3 -m ensurepip
RUN pip3 install --no-cache --upgrade pip setuptools

RUN pip install conan --upgrade

COPY . /src

WORKDIR /src
