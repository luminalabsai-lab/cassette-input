#include "PluginProcessor.h"
#include "PluginEditor.h"

// --- Forward declare the factory with C linkage so wrappers see the exact name
extern "C" JUCE_API juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter();

CassetteInputAudioProcessor::CassetteInputAudioProcessor()
    : AudioProcessor (BusesProperties()
        .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
        .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{
}

void CassetteInputAudioProcessor::prepareToPlay (double /*sampleRate*/, int /*samplesPerBlock*/) {}
void CassetteInputAudioProcessor::releaseResources() {}

bool CassetteInputAudioProcessor::isBusesLayoutSupported (const BusesLayout& l) const
{
    return l.getMainInputChannelSet()  == juce::AudioChannelSet::stereo()
        && l.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void CassetteInputAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                                juce::MidiBuffer& /*midi*/)
{
    juce::ScopedNoDenormals noDenormals;
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        buffer.applyGain (ch, 0, buffer.getNumSamples(), 1.0f);
}

juce::AudioProcessorEditor* CassetteInputAudioProcessor::createEditor()
{
    return new CassetteInputAudioProcessorEditor (*this);
}

void CassetteInputAudioProcessor::getStateInformation (juce::MemoryBlock& dest)
{
    dest.setSize (0);
}

void CassetteInputAudioProcessor::setStateInformation (const void* /*data*/, int /*sizeInBytes*/)
{
}

// --- Define the factory with C linkage and export
extern "C" JUCE_API juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CassetteInputAudioProcessor();
}

// --- Anchor to stop dead-stripping of the factory symbol by the linker
#if JUCE_MAC
__attribute__((used)) static void* juce_keep_createPluginFilter = (void*) &createPluginFilter;
#endif



