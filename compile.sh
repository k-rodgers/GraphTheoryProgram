#!/bin/bash

INCLUDE="-I../include/"

#rm -r output_data
rm -r build
rm gtp
mkdir -p build
pushd build > /dev/null
for x in $(ls ../src); do
    #g++ ${INCLUDE} -std=c++17 -c ../src/$x
    COMMAND="g++ ${INCLUDE} -std=c++17 -luuid -c ../src/$x"
    echo $COMMAND
    eval ${COMMAND}
done
rm main.o
popd > /dev/null
g++ -I./include/ -std=c++17 -g build/*.o src/main.cpp -o gtp
mkdir -p output_data
