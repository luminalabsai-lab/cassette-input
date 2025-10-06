git clone --depth 1 https://github.com/steinbergmedia/vst3sdk external/vst3sdk
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -A x64 -DVST3_SDK_DIR=$pwd\\external\\vst3sdk
cmake --build build --config Release --target ALL_BUILD -- /m
