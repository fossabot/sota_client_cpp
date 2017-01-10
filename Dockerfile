FROM ubuntu:xenial

ENV HOME /source
ENV DEBIAN_FRONTEND noninteractive
RUN mkdir $HOME
RUN apt-get update
RUN apt-get -y install gcc g++ make cmake 
RUN apt-get -y install libtool libexpat1-dev libsystemd-dev libboost-program-options-dev libboost-test-dev libboost-regex-dev libboost-dev libboost-system-dev libboost-thread-dev libboost-log-dev libjsoncpp-dev curl libcurl4-openssl-dev
RUN apt-get -y install lcov clang clang-format-3.8 

WORKDIR $HOME
COPY src/ $HOME/src/
COPY tests/ $HOME/tests/
COPY third_party/ $HOME/third_party/
COPY config/ $HOME/config/
COPY cmake-modules/ $HOME/cmake-modules/
COPY CMakeLists.txt $HOME/
RUN mkdir $HOME/build
