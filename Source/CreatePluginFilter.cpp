#include <JuceHeader.h>
#include "PluginProcessor.h"

// This must be C linkage + exported so AU/VST3 wrappers can find it.
extern "C" JUCE_API juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CassetteInputAudioProcessor();
}
