cmake_minimum_required(VERSION 3.22)
project(CassetteInput VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(JUCE)

juce_add_plugin(CassetteInput
    COMPANY_NAME            LuminaLabs
    BUNDLE_ID               com.luminalabs.cassetteinput
    IS_SYNTH                FALSE
    NEEDS_MIDI_INPUT        FALSE
    NEEDS_MIDI_OUTPUT       FALSE
    IS_MIDI_EFFECT          FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE LmLb
    PLUGIN_CODE             Csin
    FORMATS                 AU VST3
    PRODUCT_NAME            "Cassette Input"
)

target_sources(CassetteInput PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
    Source/Parameters.cpp
    Source/CreatePluginFilter.cpp   # <-- factory is compiled

    # headers optional
    Source/PluginProcessor.h
    Source/PluginEditor.h
    Source/Parameters.h
)

target_include_directories(CassetteInput PRIVATE Source)
juce_generate_juce_header(CassetteInput)

target_compile_definitions(CassetteInput PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(CassetteInput PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
)

# Keep the symbol if the linker gets too aggressive (harmless if unneeded)
if(APPLE)
  target_link_options(CassetteInput PRIVATE "-Wl,-u,_createPluginFilter")
endif()
