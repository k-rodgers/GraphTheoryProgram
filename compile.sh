#!/bin/bash

rm -r output_data
g++ -std=c++11 -c Engine.cc
g++ -std=c++11 -c Node.cc
g++ -std=c++11 -c PetersenGraph.cc
g++ -std=c++11 -c CompleteGraph.cc
g++ -std=c++11 -c Hypercube2.cc
g++ -std=c++11 -c Hypercube3.cc
g++ -std=c++11 -c Hypercube4.cc
g++ -std=c++11 -c Token.cc
g++ -std=c++11 -c RandomEngine.cc
g++ -std=c++11 *.o main.cc -o main
mkdir -p output_data
