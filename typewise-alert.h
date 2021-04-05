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
#ifndef typewise_alert_h
#define typewise_alert_h
#pragma once

/*
***************************************************************************************
* Declarations
***************************************************************************************
*/

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);



typedef struct {
    CoolingType coolingType;
    int lowerLimit;
    int upperLimit;
}CoolingTypeLimits;

#endif



