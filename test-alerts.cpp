#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include "typewise-alert.h"


TEST_CASE("infers the breach according to temperature lower than limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to temperature higher than limits") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}

TEST_CASE("No breach,Temperature within limits") {
  REQUIRE(inferBreach(22, 20, 30) == NORMAL);
}

TEST_CASE("Checks Temperarture breach based on Passive cooling type") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,40) == TOO_HIGH);
}

TEST_CASE("Checks Temperarture breach based on HI-Active cooling type") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,-1) == TOO_LOW);
}

TEST_CASE("Checks Temperarture breach based on Med-Active cooling type") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,20) == NORMAL);
}

