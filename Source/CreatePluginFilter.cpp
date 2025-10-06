#include <JuceHeader.h>
#include "PluginProcessor.h"

// Match JUCE's expectation (C++ linkage)
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CassetteInputAudioProcessor();
}
