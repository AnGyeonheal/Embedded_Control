#define LED_PIN 	5
#define BUTTON_PIN 13
#include "stm32f4xx.h"
#include "ecRCC.h"
#include "ecGPIO.h"

void setup(void);

int main(void) {
	unsigned int OUT = 1;
	unsigned int count = 0;
	// Initialiization
	setup();
	

	// Inifinite Loop 
	while(1){
		GPIO_write(GPIOA, LED_PIN, OUT);

		if(!GPIO_read(GPIOC, BUTTON_PIN) && (count > 50000)){
			OUT ^= 1UL;
			count = 0;
		}

		count++;
	}
}


// Initialiization 
void setup(void)
{
	RCC_HSI_init();	
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()
	GPIO_init(GPIOA, LED_PIN, OUTPUT);    // calls RCC_GPIOA_enable()
    GPIO_otype(GPIOA, LED_PIN, 1);
}