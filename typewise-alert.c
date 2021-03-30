/*
 ***************************************************************************************************
 * Author:             Harshitha Subramani
 * Date:               30/03/2021
 * Filename:           typewise-alert.c
 *****************************************************************************************************
*
***************************************************************************************
* Includes
***************************************************************************************
*/

#include "typewise-alert.h"
#include <stdio.h>

/*
***************************************************************************************
* Declarations
***************************************************************************************
*/

CoolingTypeLimits Limits[] ={{PASSIVE_COOLING,0,35},{HI_ACTIVE_COOLING,0,45},{MED_ACTIVE_COOLING,0,40}};

void (*display_arr[])(const char*) ={Display_ForNormal,Display_FortooHigh,Display_FortooLow};
void (*target_arr[])(BreachType) ={sendToController,sendToEmail};


/*This Function checks whether the input Temperature has breached lower limit or Upper limit value */

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

/*This Function checks whether the input Temperature has breached limits based on Cooling type*/

BreachType classifyTemperatureBreach(
    CoolingType coolingType,double temperatureInC) {
 return inferBreach(temperatureInC, Limits[coolingType].lowerLimit,Limits[coolingType].upperLimit);
}

/*This Function sends alert message to Different targets when there is temperature breach*/

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );
    (*target_arr[alertTarget])(breachType);
  
}
/*This Function sends alert message to Contro
 ller when there is temperature breach based on Cooling type*/

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

/*This Function displays that temperature is Normal*/

void Display_ForNormal(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is normal\n");
}

/*This Function displays that temperature is too high*/

void Display_FortooHigh(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
}

/*This Function displays that temperature is too high*/

void Display_FortooLow(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
}

/*This Function sends alert message to Email when there is temperature breach based on Cooling type*/

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
    (*display_arr[breachType])(recepient);
  
}
