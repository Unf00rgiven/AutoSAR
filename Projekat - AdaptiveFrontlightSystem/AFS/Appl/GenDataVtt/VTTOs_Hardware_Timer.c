/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: VTTOs
 *           Program: 
 *          Customer: N/A
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to CBD0000000_D30
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: VTTOs_Hardware_Timer.c
 *   Generation Time: 2023-03-07 15:51:55
 *           Project: MyECU - Version 1.0
 *          Delivery: CBD0000000_D30
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/


# define VTTOS_HARDWARE_TIMER_SOURCE


/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/

#include "Os.h"

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/* Holds the list of Microticks (SystemTimerTicks until the next tick of the respective counter). */
static uint64 VttOsHardwareTimerMicroticks[osdNumberOfCounters];

/**********************************************************************
 * GLOBAL FUNCTIONS
 **********************************************************************/
 
/**********************************************************************************************************************
  void osHardwareCounterEmulation_Init()
**********************************************************************************************************************/
/*! \brief      Reset the tick counter for all hardware counters.
 *********************************************************************************************************************/
void osHardwareCounterEmulation_Init(void) {
}


/**********************************************************************************************************************
  void osHardwareCounterEmulationCallback()
**********************************************************************************************************************/
/*! \brief      Replicate a tick of the system timer to all other hardware timers.
 *********************************************************************************************************************/
void osHardwareCounterEmulationCallback(void) {
}


/**********************************************************************************************************************
*  END OF FILE: VTTOs_Hardware_Timer.c
*********************************************************************************************************************/


