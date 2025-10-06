#include <JuceHeader.h>
#include "PluginProcessor.h"

// Single, global factory required by JUCE plugin clients
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CassetteInputAudioProcessor();
}
