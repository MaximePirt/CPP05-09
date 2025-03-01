FROM ubuntu:latest

RUN apt-get update && apt-get install vim g++ valgrind make -y 

RUN apt-get install git -y

ENTRYPOINT ["/bin/bash"]