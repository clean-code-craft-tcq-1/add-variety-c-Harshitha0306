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



