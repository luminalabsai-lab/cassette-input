#include "Parameters.h"

juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout() {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    // Add parameters for InputTrim, Preamp, TapeComp, EQ, WowFlutter, Noise, Crosstalk, Mix, Quality, etc.
    // e.g. layout.add(std::make_unique<juce::AudioParameterFloat>("inputTrim", "Input Trim", ...));
    return layout;
}
