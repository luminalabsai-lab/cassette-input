#pragma once
#include <JuceHeader.h>

inline juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
  // Empty for now; we’ll add real parameters once it builds cleanly
  std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
  return { params.begin(), params.end() };
}
