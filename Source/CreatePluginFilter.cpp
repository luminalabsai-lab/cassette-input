#include <JuceHeader.h>
#include "PluginProcessor.h"

// C linkage so AU/VST3 wrappers can find the unmangled symbol
extern "C" JUCE_API juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CassetteInputAudioProcessor();
}
