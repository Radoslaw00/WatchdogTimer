// ------------------------------[ main.c ]------------------------------
// -----------------------------[ INCLUDES ]------------------------------
#include <stdint.h>
//Watchdog Timer for an Embedded System
#define WDT_CONTROL_REG   (*(volatile uint8_t*)0x40001000)
#define WDT_TIMEOUT_REG   (*(volatile uint8_t*)0x40001001)
#define WDT_RESET_VALUE   0xA5
// Function to initialize the Watchdog Timer
void WDT_Init(uint8_t timeout) {
	WDT_TIMEOUT_REG = timeout; // Set the timeout value
	WDT_CONTROL_REG = 0x01;    // Enable the Watchdog Timer
}
// Function to reset the Watchdog Timer
void WDT_Reset(void) {
	WDT_CONTROL_REG = WDT_RESET_VALUE; // Reset the Watchdog Timer
}
// Main function
int main(void) {
	WDT_Init(100); // Initialize WDT with a timeout of 100 units
	while(1) {
		// Application code here
		WDT_Reset(); // Reset the Watchdog Timer periodically
	}
	return 0;
}
// ----------------------------[ END OF FILE ]----------------------------