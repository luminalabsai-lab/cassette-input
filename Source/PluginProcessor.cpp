#include "PluginProcessor.h"
#include "Parameters.h"

CassetteInputAudioProcessor::CassetteInputAudioProcessor()
: AudioProcessor (BusesProperties()
    .withInput ("Input", juce::AudioChannelSet::stereo(), true)
    .withOutput("Output", juce::AudioChannelSet::stereo(), true))
, parameters (std::make_unique<juce::AudioProcessorValueTreeState>(*this, nullptr, "PARAMETERS", createParameterLayout()))
{}

CassetteInputAudioProcessor::~CassetteInputAudioProcessor() {}

void CassetteInputAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {}
void CassetteInputAudioProcessor::releaseResources() {}

void CassetteInputAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    // Signal chain stubs: InputTrim -> Preamp -> TapeComp -> EQ -> WowFlutter -> Noise -> Crosstalk -> Output
}
juce::AudioProcessorEditor* CassetteInputAudioProcessor::createEditor() { return nullptr; } // Implement UI separately
