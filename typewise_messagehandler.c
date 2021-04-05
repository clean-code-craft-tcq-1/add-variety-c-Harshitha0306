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

/*
***************************************************************************************
* Declarations
***************************************************************************************
*/

Received_MessageTarget (*display_arr[])(const char*) ={DisplayMessage_ForNormal,DisplayMessage_FortooLow,DisplayMessage_FortooHigh};

Received_MessageTarget (*target_arr[])(BreachType) = {sendToController,sendToEmail,sendToConsole};

/*This Function sends alert message to Different targets when there is temperature breach*/

Received_MessageTarget checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );
   return( (*target_arr[alertTarget])(breachType));
  
}

/*This Function sends alert message to Contro
 ller when there is temperature breach based on Cooling type*/

Received_MessageTarget sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return StatusToController;
}

/*This Function displays that temperature is Normal*/

Received_MessageTarget DisplayMessage_ForNormal(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is normal\n");
    return StatusToEmail_Normal;
}

/*This Function displays that temperature is too high*/

Received_MessageTarget DisplayMessage_FortooHigh(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
    return StatusToEmail_TooHigh;
}

/*This Function displays that temperature is too high*/

Received_MessageTarget DisplayMessage_FortooLow(const char* recepient)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
    return StatusToEmail_TooLow;
}

/*This Function sends alert message to Email when there is temperature breach based on Cooling type*/

Received_MessageTarget sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
   return( (*display_arr[breachType])(recepient));
  
}
/*This Function sends alert message to Console when there is temperature breach based on Cooling type*/

Received_MessageTarget sendToConsole(BreachType breachType) {
  printf("The Temperature is %x\n", breachType);
  return StatusToConsole;
}


