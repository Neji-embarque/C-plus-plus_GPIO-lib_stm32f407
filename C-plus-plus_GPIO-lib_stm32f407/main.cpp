#include "my_stm32f4_gpio_lib.h"




/********** Simple delay function ************/

void delay(uint32_t milliseconds) {
    uint32_t ticks = milliseconds * 168; // Assuming 168 MHz clock frequency
    for (uint32_t i = 0; i < ticks; ++i) {
        __asm("nop"); 
    }
}
/*********************************************/

	uint8_t btnState;

int main()
{
	

	
	/***********    test 1 (1 output pin port D)   ****************/
	
	//	GPIO_InitTypeDef myGpio_InitStruct;
	
//	myGpio_InitStruct.Mode   = GPIO_MODE_OUTPUT_PP ;
//	myGpio_InitStruct.Pin    = GPIO_PIN_13 ;
//	myGpio_InitStruct.Pull   = GPIO_NOPULL ;
	
//  Gpio myOutput0 (PORTD, GPIOD, &myGpio_InitStruct);
	
//	while(1){
//					
//    delay(2000); 
//		      
//			myOutput0.LIB_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
//		
//	}
//}
		/***********fin test test 1 ************************/
	
	
	
	/***********    test 2  (2 output pin same port  ****************/
	//	GPIO_InitTypeDef myGpio_InitStruct;
//	GPIO_InitTypeDef myGpio_InitStruct_2;
//	
//	myGpio_InitStruct = __gpio_pin_params(GPIO_PIN_14, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
//	myGpio_InitStruct_2= __gpio_pin_params(GPIO_PIN_12, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);


//	
//	Gpio myOutput0 (PORTD, GPIOD, &myGpio_InitStruct);
//	Gpio myOutput1 (PORTD, GPIOD, &myGpio_InitStruct_2);
//		while(1){
//					
//    delay(2000); 
//		      
//			myOutput0.LIB_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
//			delay(2000); 
//			myOutput1.LIB_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
//			
//	}
//}
	 
	/***************** fin test 2 ***************************************/


	/***********    test 3  (2 output pin same port and 1 input pin diffrent port  ****************/
	
	GPIO_InitTypeDef myGpio_InitStruct;
	GPIO_InitTypeDef myGpio_InitStruct_2;
	GPIO_InitTypeDef myGpio_InitStruct_3;
	
	myGpio_InitStruct = __gpio_pin_params(GPIO_PIN_14, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
	myGpio_InitStruct_2= __gpio_pin_params(GPIO_PIN_12, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);

	myGpio_InitStruct_3 = __gpio_pin_params(GPIO_PIN_0, GPIO_MODE_INPUT, GPIO_NOPULL);
  
	
	Gpio myOutput0 (PORTD, GPIOD, &myGpio_InitStruct);
	Gpio myOutput1 (PORTD, GPIOD, &myGpio_InitStruct_2);
	
	Gpio myInput (PORTA, GPIOA, &myGpio_InitStruct_3);
	
		while(1){
					
    delay(2000); 
		      
			myOutput0.LIB_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
			delay(2000); 
			myOutput1.LIB_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
			
			btnState = myInput.LIB_LIB_ReadPin(GPIOA, GPIO_PIN_0);
			
	}
}
	 
	/***************** fin test 3 ***************************************/



