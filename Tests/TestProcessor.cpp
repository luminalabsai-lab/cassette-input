#include "catch2/catch.hpp"
#include "../Source/PluginProcessor.h"

TEST_CASE("Processor basic instantiation", "[processor]") {
    CassetteInputAudioProcessor proc;
    REQUIRE(proc.getName().contains("Cassette"));
}
