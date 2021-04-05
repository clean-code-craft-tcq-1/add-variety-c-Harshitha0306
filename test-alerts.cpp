#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include "typewise-alert.h"
#include "typewise_messagehandler.h"


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

TEST_CASE("Check and alert Target Controller for MED_ACTIVE_COOLING type with too low temperature ") {
     BatteryCharacter batterychar= {MED_ACTIVE_COOLING, "BMS Temperature"};
    REQUIRE(checkAndAlert(TO_CONTROLLER, batterychar,-1) == StatusToController);
}

TEST_CASE("Check and alert Target Console for PASSIVE_COOLING type with too high temperature") {
     BatteryCharacter batterychar= {PASSIVE_COOLING, "BMS Temperature"};
    REQUIRE(checkAndAlert(TO_CONSOLE, batterychar,45) == StatusToConsole);
}

TEST_CASE("Check and alert Target Email for HI-Active cooling type with too low temperature ") {
     BatteryCharacter batterychar = {HI_ACTIVE_COOLING, "BMS Temperature"};
    REQUIRE(checkAndAlert(TO_EMAIL, batterychar,-5) == StatusToEmail_TooLow);
}

TEST_CASE("Check and alert Target Email for MED_ACTIVE_COOLING cooling type with too high temperature ") {
     BatteryCharacter batterychar= {MED_ACTIVE_COOLING, "BMS Temperature"};
    REQUIRE(checkAndAlert(TO_EMAIL, batterychar,100) == StatusToEmail_TooHigh);
}

TEST_CASE("Check and alert Target Email for MED_ACTIVE_COOLING cooling type with  temperature in limits") {
     BatteryCharacter batterychar= {MED_ACTIVE_COOLING, "BMS Temperature"};
    REQUIRE(checkAndAlert(TO_EMAIL, batterychar,30) == StatusToEmail_Normal);
}
