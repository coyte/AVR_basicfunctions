#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

#include "lcd.h"
#include "usart.h"

char String[4];
int radix = 10;


// Main function
int main(void)
    {
    int count = 0;
    
	lcd_init(LCD_DISP_ON_CURSOR); 			// Initialize display
	USART_init();        					// Initialize USART

	// Put a test string on the display
	lcd_clrscr(); 							// Clear display and home cursor
	lcd_gotoxy(0,0);
	lcd_puts("Display testing");

	// Infinite loop
	while (1)
		{
			count++;
			itoa(count, String, radix);		// Convert integer to string
			USART_putstring(String);    	// Pass the string to the USART_putstring function and sends it over the serial
			USART_putstring("\n");
			//lcd_puts(" ");					// Clear line
			lcd_gotoxy(0,1);				// Go to second line
			lcd_puts(String);
			_delay_ms(1000);        		// Delay for 1 second
		} 									//end while loop
	}									 	//end main

