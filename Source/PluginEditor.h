#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class CassetteInputAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    CassetteInputAudioProcessorEditor (CassetteInputAudioProcessor&);
    ~CassetteInputAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CassetteInputAudioProcessorEditor)
};
