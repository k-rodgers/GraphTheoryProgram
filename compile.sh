#!/bin/bash

rm -r output_data
g++ -std=c++11 -c Engine.cc
g++ -std=c++11 -c Node.cc
g++ -std=c++11 -c PetersenGraphRandom.cc
g++ -std=c++11 -c CompleteGraphRandom.cc
g++ -std=c++11 -c Hypercube2Random.cc
g++ -std=c++11 -c Hypercube3Random.cc
g++ -std=c++11 -c Hypercube4Random.cc
g++ -std=c++11 -c PetersenGraphLogical.cc
g++ -std=c++11 -c CompleteGraphLogical.cc
g++ -std=c++11 -c Hypercube2Logical.cc
g++ -std=c++11 -c Hypercube3Logical.cc
g++ -std=c++11 -c Hypercube4Logical.cc
g++ -std=c++11 -c Token.cc
g++ -std=c++11 -c RandomEngine.cc
g++ -std=c++11 *.o main.cc -o main
mkdir -p output_data
