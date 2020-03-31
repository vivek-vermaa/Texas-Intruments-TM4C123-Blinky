// BranchingFunctionsDelays.c 
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to 
// toggle an LED while a button is pressed and 
// turn the LED on when the button is released.  
// This lab will use the hardware already built into the LaunchPad.
// Vivek Verma
// March 31st, 2020

// built-in connection: PF0 connected to negative logic momentary switch, SW2
// built-in connection: PF1 connected to red LED
// built-in connection: PF2 connected to blue LED
// built-in connection: PF3 connected to green LED
// built-in connection: PF4 connected to negative logic momentary switch, SW1



	#include "TExaS.h"
	#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
	#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
	#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
	#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
	#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
	#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
	#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
	#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
	#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
	#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))  
		
	// basic functions defined at end of startup.s
	void DisableInterrupts(void); // Disable interrupts
	void EnableInterrupts(void);  // Enable interrupts
	void PortF_Init(void);
	void Delay100ms(unsigned long time);
	unsigned long SW1;

	int main(void){ unsigned long volatile delay;
		TExaS_Init(SW_PIN_PF4, LED_PIN_PF2);  // activate grader and set system clock to 80 MHz
		// initialization goes here
		PortF_Init();
		EnableInterrupts();           // enable interrupts for the grader
		while(1)
		{
			
			SW1 = GPIO_PORTF_DATA_R & 0x10;  // Enable port Port F4 as a switch
			
			if(SW1 == 0)
			{ 
				GPIO_PORTF_DATA_R ^=  0x04;
				Delay100ms(1);	
			}
			else
			{
				GPIO_PORTF_DATA_R = 0x04;
      }				
			
		}
	}

	void PortF_Init(void)
	{ 
		volatile unsigned long delay;
		SYSCTL_RCGC2_R |= 0x20; 					  //1) Enable Clock gating register for Port F
		delay = SYSCTL_RCGC2_R;             //2  impart delary till 2 clock cycles till it settles
		GPIO_PORTF_AMSEL_R = 0x00;         // 3) disable analog function
		GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
		GPIO_PORTF_DIR_R |= 0x04;          // 5) PF4 input, PF2 output   
		GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
		GPIO_PORTF_DEN_R |= 0x14;          // 7) enable digital pins PF4-PF0    
		GPIO_PORTF_PUR_R |= 0x10;          //8)enable pullup resistors on PF4   	
		GPIO_PORTF_DATA_R |=0x04;
		
	}

	void Delay100ms(unsigned long time)
{
  unsigned long i;
  while(time > 0){
    i = 1333333;  // this number means 100ms
    while(i > 0){
      i = i - 1;
    }
    time = time - 1; // decrements every 100 ms
  }
}

