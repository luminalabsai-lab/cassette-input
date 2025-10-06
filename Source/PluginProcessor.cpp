#include "PluginProcessor.h"
#include "PluginEditor.h"

CassetteInputAudioProcessor::CassetteInputAudioProcessor()
: AudioProcessor (BusesProperties()
    .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
    .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{}

void CassetteInputAudioProcessor::prepareToPlay (double, int) {}
void CassetteInputAudioProcessor::releaseResources() {}

bool CassetteInputAudioProcessor::isBusesLayoutSupported (const BusesLayout& l) const
{
  return l.getMainInputChannelSet()  == juce::AudioChannelSet::stereo()
      && l.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void CassetteInputAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
  juce::ScopedNoDenormals noDenormals;
  for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    buffer.applyGain (ch, 0, buffer.getNumSamples(), 1.0f); // passthrough
}

juce::AudioProcessorEditor* CassetteInputAudioProcessor::createEditor()
{
  return new CassetteInputAudioProcessorEditor (*this);
}

void CassetteInputAudioProcessor::getStateInformation (juce::MemoryBlock& dest)   { dest.setSize (0); }
void CassetteInputAudioProcessor::setStateInformation (const void*, int)          {}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new CassetteInputAudioProcessor(); }
