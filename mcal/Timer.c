/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer.c
 *        \brief  it is the file that contains the Timer and delay functions(systick)
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <Timer.h>
#include <Bit_Math.h>
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
	volatile int SysTick_intFlag;
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void NVIC_int()       
* \Description     : this Handler is for the Systick interrupt                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/

	void SysTick_Handler (){ 
			(*(volatile uint32_t *)(((uint32_t)	STCTRL)))= 0x00000006;
			(*(volatile uint32_t *)(((uint32_t)	STReload)))= 0x00000000;
			SysTick_intFlag=1;
			return;
	}


/******************************************************************************
* \Syntax          : void system_delay(int time_ms)       
* \Description     : this function creates a delay of tthe time mentioned above in ms                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : time_ms "the user inserts a time in ms)    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void system_delay(int time_ms){	
	while(time_ms>1000){
		time_ms=time_ms-1000;
		int time_ms2=1000;
		SysTick_intFlag=0;	
		uint32_t time_in_ticks=time_ms2*System_Clock*1000;
		(*(volatile uint32_t *)(((uint32_t)	STCTRL)))= 0x00000007;
		(*(volatile uint32_t *)(((uint32_t)	STReload)))= time_in_ticks;			
		while(1){
			if (SysTick_intFlag==1){
			SysTick_intFlag=0;
			break;
			}
		}
	}
	SysTick_intFlag=0;	
	uint32_t time_in_ticks=time_ms*System_Clock*1000;
	(*(volatile uint32_t *)(((uint32_t)	STCTRL)))= 0x00000007;
	(*(volatile uint32_t *)(((uint32_t)	STReload)))= time_in_ticks;
		while(1){
			if (SysTick_intFlag==1){
			SysTick_intFlag=0;
			break;
			}
		}
	(*(volatile uint32_t *)(((uint32_t)	STCTRL)))= 0x00000000;
	systick_init();
}
/******************************************************************************
* \Syntax          : void systick_init()       
* \Description     : this function initiates systick timer for use in the start process                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : none    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
		void systick_init(){
			uint32_t time_in_ticks=Timer_Config*System_Clock*1000;
			(*(volatile uint32_t *)(((uint32_t)	STReload)))= time_in_ticks;	
		}			
/******************************************************************************
* \Syntax          : void systick_Start()       
* \Description     : this function starts systick timer it will start counting and when it hits zero it will restart counting                                 
*                    no interrupt is genertated                                                         
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : none  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/		
		void systick_Start(){
		(*(volatile uint32_t *)(((uint32_t)	STCTRL)))= 0x00000005;
		}			
/******************************************************************************
* \Syntax          : void systick_Stop()       
* \Description     : it will stop the counter                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : none  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/		
		void systick_Stop(){
			(*(volatile uint32_t *)(((uint32_t)	STCTRL)))= 0x00000000;
		}			
/******************************************************************************
* \Syntax          : volatile uint32_t systick_GetCurrentValue()()       
* \Description     : it will return the current counting value                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : none  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/		
		volatile uint32_t systick_GetCurrentValue(){
			return *((volatile uint8_t*)(STCurrent));
		}
/******************************************************************************
* \Syntax          : volatile uint32_t systick_ZeroCheck()       
* \Description     : will check if the it has reached zero                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : none  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
		volatile int systick_ZeroCheck(){
			return *((volatile uint8_t*)(STCTRL))*0x10000 ;
		}

	
/**********************************************************************************************************************
 *  END OF FILE: Nvic.c
 *********************************************************************************************************************/
