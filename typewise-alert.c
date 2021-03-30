#include "typewise-alert.h"
#include <stdio.h>

CoolingTypeLimits Limits[] ={{PASSIVE_COOLING,0,35},{HI_ACTIVE_COOLING,0,45},{MED_ACTIVE_COOLING,0,40}};

void (*display_arr[])(const char*) ={Display_ForNormal,Display_FortooHigh,Display_FortooLow};
void (*target_arr[])(BreachType) ={sendToController,sendToEmail};

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType,double temperatureInC) {
 return inferBreach(temperatureInC, Limits[coolingType].lowerLimit,Limits[coolingType].upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );
    (*target_arr[alertTarget])(breachType);
  
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}


void Display_ForNormal(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is normal\n");
}

void Display_FortooHigh(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
}

void Display_FortooLow(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
    (*display_arr[breachType])(recepient);
  
}
