#!/bin/bash
set -e
git clone --depth 1 https://github.com/steinbergmedia/vst3sdk external/vst3sdk
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" -DVST3_SDK_DIR=$(pwd)/external/vst3sdk
cmake --build build --config Release --target ALL_BUILD --parallel
