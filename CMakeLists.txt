cmake_minimum_required(VERSION 3.22)
project(CassetteInput VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use JUCE submodule in ./JUCE
add_subdirectory(JUCE)

juce_add_plugin(CassetteInput
    COMPANY_NAME LuminaLabs
    BUNDLE_ID com.luminalabs.cassetteinput
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE LmLb
    PLUGIN_CODE Csin
    FORMATS AU VST3
    PRODUCT_NAME "Cassette Input"

    # All plugin sources go here so they link into AU/VST3 wrappers
    SOURCES
        Source/PluginProcessor.cpp
        Source/PluginEditor.cpp
        Source/Parameters.cpp
        Source/CreatePluginFilter.cpp
        # headers are optional but ok to list
        Source/PluginProcessor.h
        Source/PluginEditor.h
        Source/Parameters.h
)

target_include_directories(CassetteInput PRIVATE Source)
juce_generate_juce_header(CassetteInput)

target_compile_definitions(CassetteInput PRIVATE
    JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(CassetteInput PRIVATE
    juc
