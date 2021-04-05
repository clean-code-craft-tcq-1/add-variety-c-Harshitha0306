/*
 ***************************************************************************************************
 * Author:             Harshitha Subramani
 * Date:               30/03/2021
 * Filename:           typewise-messagehandler.c
 *****************************************************************************************************
*
***************************************************************************************
* Includes
***************************************************************************************
*/

#include "typewise-alert.h"
#include "typewise_messagehandler.h"


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

void DisplayMessage_ForNormal(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is normal\n");
}

/*This Function displays that temperature is too high*/

void DisplayMessage_FortooHigh(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
}

/*This Function displays that temperature is too high*/

void DisplayMessage_FortooLow(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
}

/*This Function sends alert message to Email when there is temperature breach based on Cooling type*/

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
    (*display_arr[breachType])(recepient);
  
}
/*This Function sends alert message to Console when there is temperature breach based on Cooling type*/

void sendToConsole(BreachType breachType) {
  printf("The Temperature is %x\n", breachType);
}
