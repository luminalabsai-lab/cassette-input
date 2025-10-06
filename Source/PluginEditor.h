#pragma once
#include <JuceHeader.h>
class CassetteInputAudioProcessor; // fwd

class CassetteInputAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
  explicit CassetteInputAudioProcessorEditor (CassetteInputAudioProcessor& p);
  ~CassetteInputAudioProcessorEditor() override = default;

  void paint (juce::Graphics&) override;
  void resized() override;

private:
  CassetteInputAudioProcessor& processor; // keep a ref
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CassetteInputAudioProcessorEditor)
};
