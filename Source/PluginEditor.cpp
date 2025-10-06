#include "PluginEditor.h"

CassetteInputAudioProcessorEditor::CassetteInputAudioProcessorEditor (CassetteInputAudioProcessor& p)
: AudioProcessorEditor (&p) {
    setSize (600, 400);
}

CassetteInputAudioProcessorEditor::~CassetteInputAudioProcessorEditor() {}

void CassetteInputAudioProcessorEditor::paint (juce::Graphics& g) {
    g.fillAll (juce::Colours::black);
    // Draw cassette window stub, meters, big knobs...
}

void CassetteInputAudioProcessorEditor::resized() {}
