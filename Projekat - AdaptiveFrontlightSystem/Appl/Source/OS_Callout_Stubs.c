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
 *              File: Os_Callout_Stubs.c
 *   Generation Time: 2016-03-17 09:06:54
 *           Project: MyECU - Version 1.0
 *          Delivery: CBD0000000_D30
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/


# define OS_CALLOUT_STUBS_SOURCE


/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/

#include "Std_Types.h"
#include "osek.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_Include>
 *********************************************************************************************************************/
#include "EcuM.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/


/**********************************************************************
 * GLOBAL FUNCTIONS
 **********************************************************************/

/* OS Error Hook */
osqFunc1 void osqFunc2 ErrorHook(StatusType Error)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ErrorHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

/* OS Post Task Hook */
#if osdPostTaskHook
osqFunc1 void osqFunc2 PostTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PostTaskHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}
#endif

/* OS Pre Task Hook */
#if osdPreTaskHook
osqFunc1 void osqFunc2 PreTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PreTaskHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}
#endif

/* OS Protection Hook */
#if ((osdSC == SC2) || (osdSC == SC3) || (osdSC == SC4))
ProtectionReturnType ProtectionHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ProtectionHook>
 *********************************************************************************************************************/
  return 0;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}
#endif

/* OS Shutdown Hook */
osqFunc1 void osqFunc2 ShutdownHook(StatusType Error)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ShutdownHook>
 *********************************************************************************************************************/
  EcuM_Shutdown();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

/* OS Startup Hook */
osqFunc1 void osqFunc2 StartupHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_StartupHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}


/* Unrecognized User Blocks */

#if 0
#endif

/**********************************************************************************************************************
*  END OF FILE: OS_Callout_Stubs.c
*********************************************************************************************************************/


