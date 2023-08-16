FROM debian:bullseye-20230522

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update

# tool PART
RUN apt-get update && apt-get install -y git cmake make clang-format libncurses-dev 

# X86 PART
RUN apt-get update && apt-get install -y gcc g++ gdb swig grep dbus libmbedtls-dev libdbus-1-dev libczmq-dev

# GRAPH PART
RUN apt-get update && apt install -y graphviz plantuml

# PYTHON PART
RUN apt-get update && apt install -y python3 python3-pip
COPY tool/env.txt /tmp
RUN python3 -m pip install -r /tmp/env.txt

RUN apt-get update && apt-get install -y clang

# RIGHT PART
RUN apt-get update && apt install -y sudo
RUN echo "lapin ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
RUN useradd lapin -m -s /bin/bash

# LOCALES PART
RUN apt-get update && apt-get install -y locales
RUN sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    dpkg-reconfigure --frontend=noninteractive locales && \
    update-locale LANG=en_US.UTF-8

ENV LANG en_US.UTF-8
ENV SHELL "/bin/bash"

RUN ln -sf /bin/bash /bin/sh

USER lapin
