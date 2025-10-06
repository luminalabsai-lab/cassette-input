#!/bin/bash
set -e
echo "Starting build script"
git clone --depth 1 https://github.com/steinbergmedia/vst3sdk external/vst3sdk || echo "VST3SDK already exists"
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" -DVST3_SDK_DIR=$(pwd)/external/vst3sdk
cmake --build build --config Release --target ALL_BUILD --parallel
echo "Build script finished"
