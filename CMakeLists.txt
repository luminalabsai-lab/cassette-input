cmake_minimum_required(VERSION 3.15)
project(CassetteInput VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(JUCE_DIR "${CMAKE_SOURCE_DIR}/JUCE")
add_subdirectory(JUCE)

juce_add_plugin(CassetteInput
    BUNDLE_ID com.luminalabs.cassetteinput
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE LmLb
    PLUGIN_CODE Csin
    FORMATS AU VST3
    PRODUCT_NAME "CassetteInput"
)

target_sources(CassetteInput PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
    Source/Parameters.cpp
    Source/Parameters.h
    Source/Preamp.cpp
    Source/Preamp.h
    Source/TapeComp.cpp
    Source/TapeComp.h
    Source/HeadBumpEQ.cpp
    Source/HeadBumpEQ.h
    Source/EQ.cpp
    Source/EQ.h
    Source/WowFlutter.cpp
    Source/WowFlutter.h
    Source/Noise.cpp
    Source/Noise.h
    Source/Metering.cpp
    Source/Metering.h
    Source/Oversampling.cpp
    Source/Oversampling.h
    Source/UI.cpp
    Source/UI.h
)

target_include_directories(CassetteInput PRIVATE
    Source
)

juce_generate_juce_header(CassetteInput)

# Resources
file(GLOB SVG_FILES "Resources/*.svg")
file(GLOB JSON_FILES "Resources/*.json")
target_sources(CassetteInput PRIVATE ${SVG_FILES} ${JSON_FILES})

# Tests
add_subdirectory(Tests)

# Link JUCE modules
target_link_libraries(CassetteInput PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
    juce::juce_gui_extra
)
