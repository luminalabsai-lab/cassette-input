add_executable(CassetteInputTests
    CatchMain.cpp
    TestProcessor.cpp
    GoldenHarness.cpp
)

target_link_libraries(CassetteInputTests PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
    juce::juce_gui_extra
)

target_include_directories(CassetteInputTests PRIVATE
    ../Source
)
