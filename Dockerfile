#
# Dockerfile for SFML C++ Project building and testing
#

FROM ubuntu:18.04

RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
    git \

    # GNU c++ compiler
    g++ \
    libegl1-mesa \ 
    libgl1-mesa-dev \
    libglu1-mesa \
    libglu1-mesa-dev \
    libsfml-dev \
    libgtest-dev \
    #GNU Binutils as the GNU linker and the GNU assembler
    binutils-dev \ 
    libtool \
    #openSSL is needed for CMAKE
    libssl-dev

RUN wget http://www.cmake.org/files/v3.18/cmake-3.18.0.tar.gz

RUN tar -xvf cmake-3.18.0.tar.gz

RUN cd cmake-3.18.0 && \
    ./bootstrap && \
    make && \
    make install

CMD tail -f /dev/null