#!/bin/bash

set -e

INCLUDE="-I ../include/"

#rm -r output_data
rm -r build && true
rm gtp && true
mkdir -p build
pushd build > /dev/null

for x in $(find ../src | grep \\.cpp); do
    #g++ ${INCLUDE} -std=c++17 -c ../src/$x
    COMMAND="g++ ${INCLUDE} -std=c++17 -c $x -luuid"
    echo $COMMAND
    eval ${COMMAND}
done
rm main.o
popd > /dev/null
g++ -I./include/ -std=c++17 -g build/*.o src/main.cpp -luuid -o gtp
mkdir -p output_data
