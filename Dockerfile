FROM ubuntu:20.04

RUN apt -y update && apt -y upgrade && apt install --no-install-recommends -y build-essential nasm genisoimage && rm -rf /var/lib/apt/lists/*

VOLUME /root/env
WORKDIR /root/env

CMD ["make", "os.iso"]