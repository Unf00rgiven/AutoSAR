/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtApBatteryManager.c
 *        Config:  C:/nit-au-03/Boki/AUTOSAR_Exercises/AFS/MyECU.dpa
 *     SW-C Type:  CtApBatteryManager
 *  Generated at:  Sat Mar 11 14:23:21 2023
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  C-Code implementation template for SW-C <CtApBatteryManager>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_Rte_0777, MD_Rte_0779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CtApBatteryManager.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *
 *********************************************************************************************************************/


#define CtApBatteryManager_START_SEC_CODE
#include "CtApBatteryManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApBatteryManager_WriteMode
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_PpBatteryMode_BatteryModes(uint8 mode)
 *   Modes of Rte_ModeType_MdgBswMBatteryModes:
 *   - RTE_MODE_MdgBswMBatteryModes_BATTERY_HIGH
 *   - RTE_MODE_MdgBswMBatteryModes_BATTERY_LOW
 *   - RTE_MODE_MdgBswMBatteryModes_BATTERY_MEDIUM
 *   - RTE_TRANSITION_MdgBswMBatteryModes
 *   Std_ReturnType Rte_Switch_PpBswMBatteryLevel_BswM_MDGP_MdgBswMBatteryModes(uint8 mode)
 *   Modes of Rte_ModeType_MdgBswMBatteryModes:
 *   - RTE_MODE_MdgBswMBatteryModes_BATTERY_HIGH
 *   - RTE_MODE_MdgBswMBatteryModes_BATTERY_LOW
 *   - RTE_MODE_MdgBswMBatteryModes_BATTERY_MEDIUM
 *   - RTE_TRANSITION_MdgBswMBatteryModes
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_PpBatterLevelIn_ReadChannel(uint8 *value)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Event_DTC_0x000002_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApBatteryManager_WriteMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtApBatteryManager_CODE) RCtApBatteryManager(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApBatteryManager
 *********************************************************************************************************************/
	uint8 battery_level = 0;
	(void)Rte_Call_PpBatterLevelIn_ReadChannel(&battery_level);

	if (battery_level < 31)
	{
		(void)Rte_Call_Event_DTC_0x000002_SetEventStatus(DEM_EVENT_STATUS_FAILED);
		(void)Rte_Switch_PpBatteryMode_BatteryModes(RTE_MODE_MdgBswMBatteryModes_BATTERY_LOW);
		(void)Rte_Switch_CtApBatteryManager_PpBswMBatteryLevel_BswM_MDGP_MdgBswMBatteryModes(RTE_MODE_MdgBswMBatteryModes_BATTERY_LOW);
	}
	else if (battery_level < 71)
	{
		(void)Rte_Switch_PpBatteryMode_BatteryModes(RTE_MODE_MdgBswMBatteryModes_BATTERY_MEDIUM);
		(void)Rte_Switch_CtApBatteryManager_PpBswMBatteryLevel_BswM_MDGP_MdgBswMBatteryModes(RTE_MODE_MdgBswMBatteryModes_BATTERY_MEDIUM);
	}
	else
	{
		(void)Rte_Switch_PpBatteryMode_BatteryModes(RTE_MODE_MdgBswMBatteryModes_BATTERY_HIGH);
		(void)Rte_Switch_CtApBatteryManager_PpBswMBatteryLevel_BswM_MDGP_MdgBswMBatteryModes(RTE_MODE_MdgBswMBatteryModes_BATTERY_HIGH);
	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtApBatteryManager_STOP_SEC_CODE
#include "CtApBatteryManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:RCtApBatteryManager_doc)  *****************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RDataServices_WriteBatteryValue_doc)  *****************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RDataServices_WriteBatteryValue)  ****************/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:RDataServices_ReadBatteryValue_doc)  ******************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_BatteryValue_ReadData)  *************/


/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0777:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

   MD_Rte_0779:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

*/
