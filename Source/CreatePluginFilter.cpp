#include <JuceHeader.h>
#include "PluginProcessor.h"

// C linkage + export so AU/VST3 wrappers can find the factory
extern "C" JUCE_API juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CassetteInputAudioProcessor();
}
