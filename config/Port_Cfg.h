/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.H
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef Port_cfg
#define Port_cfg

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include <stdint.h>
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
	#define GPIOA_data					0x40004000
	#define GPIOB_data					0x40005000
	#define GPIOC_data					0x40006000
	#define GPIOD_data					0x40007000
	#define GPIOE_data					0x40024000
	#define GPIOF_data					0x40025000
	typedef uint8_t  Dio_port;
	#define	PORTA			0
	#define	PORTB			1
	#define	PORTC			2
	#define	PORTD			3
	#define	PORTE			4
	#define	PORTF			5	

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* Portt_Cfg_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/