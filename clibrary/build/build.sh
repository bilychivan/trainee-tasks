#!/bin/bash

cp ../library/include/lyslib.h ../demo/lyslib.h
cmake ../
make
./demo/lyslib_demo
