#!/bin/bash
mkdir -p temp && cd temp && wget http://dlib.net/files/dlib-19.21.tar.bz2
tar -xf dlib-19.21.tar.bz2 && mv dlib-19.21/ ../dlib
