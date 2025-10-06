#include <JuceHeader.h>
#include "PluginProcessor.h"

// Exported C symbol that all JUCE wrappers look up.
extern "C" JUCE_API juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CassetteInputAudioProcessor();
}
