#pragma once
#include <JuceHeader.h>
#include "Parameters.h"

class CassetteInputAudioProcessor : public juce::AudioProcessor {
public:
    CassetteInputAudioProcessor();
    ~CassetteInputAudioProcessor() override;

    // JUCE overrides
    void prepareToPlay(double, int) override;
    void releaseResources() override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }
    const juce::String getName() const override { return "Cassette Input"; }
    // ... Other overrides omitted for brevity

    std::unique_ptr<juce::AudioProcessorValueTreeState> parameters;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CassetteInputAudioProcessor)
};
