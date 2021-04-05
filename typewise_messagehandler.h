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

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void DisplayMessage_ForNormal(const char* recepient);
void DisplayMessage_FortooHigh(const char* recepient);
void DisplayMessage_FortooLow(const char* recepient);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void sendToConsole(BreachType breachType);


void (*display_arr[])(const char*) ={DisplayMessage_ForNormal,DisplayMessage_FortooHigh,DisplayMessage_FortooLow};

void (*target_arr[])(BreachType) = {sendToController,sendToEmail,sendToConsole};


#endif /* typewise_messagehandler_h */
