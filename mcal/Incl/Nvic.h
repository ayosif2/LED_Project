/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Nvic.h
 *       Module:  Nvic 
 *
 *  Description:  the header file for the Nvic driver file     
 *  
 *********************************************************************************************************************/
#ifndef Nvic_h
#define Nvic_h

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
	#include <stdint.h>
	#include "Nvic_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

	
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct{
	NVIC_state		state;
	uint8_t 			Priority;
	
}NVIC_CfgType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
	extern const NVIC_CfgType NVIC_Cfg[140];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
		void NVIC_int();

#endif  /* Nvic.h */

/**********************************************************************************************************************
 *  END OF FILE: Nvic.h
 *********************************************************************************************************************/