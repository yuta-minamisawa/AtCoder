#!/bin/bash

echo $1

g++ -std=c++17 $1.cpp -O2
oj t -t 3