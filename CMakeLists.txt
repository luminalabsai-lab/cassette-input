cmake_minimum_required(VERSION 3.22)
project(CassetteInput VERSION 1.0.0 LANGUAGES C CXX)  # note: C and C++

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Safety: if JUCE falls back, keep IDs space-free
set(JUCE_COMPANY_NAME LuminaLabs)
set(JUCE_PRODUCT_NAME_STRING "Cassette Input")

include(FetchContent)
FetchContent_Declare(juce
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG 7.0.12)
FetchContent_MakeAvailable(juce)

juce_add_plugin(CassetteInput
    BUNDLE_ID com.luminalabs.cassetteinput   # no spaces
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE LmLb
    PLUGIN_CODE Csin
    FORMATS AU VST3
    PRODUCT_NAME "Cassette Input"
)

target_sources(CassetteInput PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
    Source/Parameters.cpp
    Source/Parameters.h
)

target_include_directories(CassetteInput PRIVATE Source)
juce_generate_juce_header(CassetteInput)

target_compile_definitions(CassetteInput PRIVATE
  JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(CassetteInput PRIVATE juce::juce_audio_utils juce::juce_dsp)

