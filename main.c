
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0b00111100; //Set Data Direction Register so PD 2,3,4,5 are outputs while  PD 0,1 are Inputs
    PORTD |= (1 << PD0);    // enable pull-up resistor
    PORTD |= (1 << PD1);    // enable pull-up resistor
    int i;      /* Define a global variable i */
    i = 1;      /* Assign i the value 1 */
    int b;      /* Define a global variable i */
    b = 0;      /* Assign i the value 1 */
    while(1)
    {   
		
		if (b==1) {
			PORTD |=  (1 << PD3);//Switch on FinishLED
			PORTD &= ~(1 << PD2);// Switch off  Discharger
			PORTD &= ~(1 << PD4);// Switch off  Charger
			PORTD &= ~(1 << PD5);// Switch off  ChargerLED
			
			 }
		else
		{ 		
		
        if (ACSR & (1 << ACO)) {            // comparator output high?
            
            PORTD &= ~(1 << PD2);// Switch off  Discharger
            PORTD |=  (1 << PD4);//Switch on Charger
            PORTD |=  (1 << PD5);//Switch on ChargerLED
		    
			for (i=0;i<1000;i++) //Waste time 
			{ PORTD |=  (1 << PD5); //Switch on ChargerLED
			 _delay_ms(60000); //seconds due to looping 1000 times
			 b = 1;}
			}
        
        else {
            // comparator output low, Discharger stays on                                        
        PORTD |=  (1 << PD2); // Switch on the Discharger
	    PORTD &= ~(1 << PD4); // Switch off Charger		
	    PORTD &= ~(1 << PD5); // Switch off ChargerLED	
        }}}

			} 
                   


