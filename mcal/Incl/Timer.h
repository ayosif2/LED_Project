/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Timer.h
 *       Module:  TTimer module
 *
 *  Description:  the header file for the Timer.c file     
 *  
 *********************************************************************************************************************/
	#ifndef Timer_H
	#define Timer_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
	#include <stdint.h>
	#include <Timer_Cfg.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
	
	#define systick_Base    	0xE000E000
	#define STCTRL						0xE000E010
	#define STReload					0xE000E014
	#define STCurrent					0xE000E018
	
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
	extern volatile int SysTick_intFlag;
	extern const int Timer_Config;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
	void SysTick_Handler();
	void system_delay(int time_ms);
	void systick_init();
	void systick_Start();
	void systick_Stop();
	volatile uint32_t systick_GetCurrentValue();
	volatile int systick_ZeroCheck();
	#endif  /* Timer.h */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/