FROM ubuntu:20.04

RUN \
    apt-get update && \
    apt-get --no-install-recommends -y install \
        build-essential \
        ca-certificates \
        clang-11 \
        cmake \
        llvm-11 \
        libssl-dev \
        libbz2-dev \
        libz-dev \
        libicu-dev \
        git \
        python3 \
        python3-requests \
        python-is-python3 \
        libboost-all-dev \
        mysql-client && \
    ln -s /usr/bin/clang++-11 /usr/bin/clang++ && \
    ln -s /usr/bin/clang-11 /usr/bin/clang

