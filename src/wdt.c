// ------------------------------------[ wdt.c ]-------------------------------------------
// This file contains the implementation of a Watchdog Timer (WDT) for an embedded system.
// -----------------------------------[ INCLUDES ]-----------------------------------------
#include <stdint.h> // Library for standard integer types
// ----------------------------------[ REGISTERS ]-----------------------------------------
#define WDT_CONTROL_REG   (*(volatile uint8_t*)0x40001000)	// Control register
#define WDT_TIMEOUT_REG   (*(volatile uint8_t*)0x40001001)	// Timeout register
#define WDT_RESET_VALUE   0xA5								// Value to reset the WDT
// ----------------------------------[ WDT_Init ]------------------------------------------
void WDT_Init(uint8_t timeout) {
	WDT_TIMEOUT_REG = timeout;								// Set the timeout value
	WDT_CONTROL_REG = 0x01;									// Enable the Watchdog Timer
}
// -----------------------------------[ WDT_Reset ]----------------------------------------
void WDT_Reset(void) {
	WDT_CONTROL_REG = WDT_RESET_VALUE;						// Reset the Watchdog Timer
}
// ----------------------------------[ END OF FILE ]---------------------------------------