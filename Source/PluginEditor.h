#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h" // or forward declare the class

class CassetteInputAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit CassetteInputAudioProcessorEditor (CassetteInputAudioProcessor& p);
    ~CassetteInputAudioProcessorEditor() override = default;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CassetteInputAudioProcessorEditor)
};
