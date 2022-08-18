#include "Port.h"
#include "bit_math.h"	
#include "Nvic.h"
#include "Timer.h"
#include "LED.h"
	
int main(){
	NVIC_int();
	Port_Init ();	

	while(1){
	LED_Blink(3000,5000,PORTC,0);
	}
	}

