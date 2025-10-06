#include "PluginEditor.h"
#include "PluginProcessor.h"

CassetteInputAudioProcessorEditor::CassetteInputAudioProcessorEditor (CassetteInputAudioProcessor& p)
: juce::AudioProcessorEditor (&p), processor (p)
{
  setSize (600, 400);
}

void CassetteInputAudioProcessorEditor::paint (juce::Graphics& g)
{
  g.fillAll (juce::Colours::black);
  g.setColour (juce::Colours::white);
  g.drawFittedText ("Cassette Input (stub UI)", getLocalBounds(), juce::Justification::centred, 1);
}

void CassetteInputAudioProcessorEditor::resized() {}
