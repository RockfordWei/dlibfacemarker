#!/bin/bash
mkdir -p build && pushd . && cd build && cmake .. && cmake --build . --config Release && popd
#mkdir -p build && pushd . && cd build && cmake .. && cmake --build . --config Debug && popd
