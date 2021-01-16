#!/bin/bash
mkdir -p /opt/build-linux && \
cd /opt/build-linux/ && \
cmake .. && \
cmake --build . --config Release