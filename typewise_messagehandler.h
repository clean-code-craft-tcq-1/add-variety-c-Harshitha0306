/*
 ***************************************************************************************************
 * Author:             Harshitha Subramani
 * Date:               30/03/2021
 * Filename:           typewise_messagehandler.c
 *****************************************************************************************************
*
***************************************************************************************
* Includes
***************************************************************************************
*/

#ifndef typewise_messagehandler_h
#define typewise_messagehandler_h

#include <stdio.h>

/*
***************************************************************************************
* Declarations
***************************************************************************************
*/

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_CONSOLE
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef enum {
    StatusToController,
    StatusToEmail_Normal,
    StatusToEmail_TooLow,
    StatusToEmail_TooHigh,
    StatusToConsole
}Received_MessageTarget;

Received_MessageTarget checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);



Received_MessageTarget DisplayMessage_ForNormal(const char* recepient);
Received_MessageTarget DisplayMessage_FortooHigh(const char* recepient);
Received_MessageTarget DisplayMessage_FortooLow(const char* recepient);

Received_MessageTarget sendToController(BreachType breachType);
Received_MessageTarget sendToEmail(BreachType breachType);
Received_MessageTarget sendToConsole(BreachType breachType);





#endif /* typewise_messagehandler_h */
