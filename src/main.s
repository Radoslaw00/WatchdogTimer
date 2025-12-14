@ ------------------------------[ main.s ]----------------------------------
@ This file contains the assembly implementation of the main function      |
@ ----------------------------[ DESCRIPTION ]-------------------------------
@ ARM Cortex-M Tiny Main for Watchdog Experiment.                          |
@ Simulates main loop in assembly calling C WDT functions.                 |
@ ------------------------------[ AUTHOR ]----------------------------------
@ GitHub: https://github.com/Radoslaw00                                    |
@ ------------------------------[ LICENSE ]---------------------------------
@ This code is licensed under the MIT License.                             |
@ -----------------------------[ REFERENCE ]--------------------------------
@ C Equivalent:                                                            |
@                                                                          |
@ int main(void) {                                                         |
@     WDT_Init(100);                                                       |
@     while(1) {                                                           |
@         WDT_Reset();                                                     |
@     }                                                                    |
@ }                                                                        |
@ ---------------------------[ INCLUDES ]-----------------------------------
    AREA Reset, CODE, READONLY              @ Define code section          |
    EXPORT main 						    @ Export main symbol           |
@ ---------------------------[ EXTERNALS ]----------------------------------
    IMPORT WDT_Init                         @ C function to initialize WDT |
    IMPORT WDT_Reset                        @ C function to reset WDT      |
@ -----------------------------[ CORE ]-------------------------------------
main                                                                       |
    @ int main(void)    ---[ Start WDT ]---                                |
    MOV     R0, #100                        @ timeout value                |
    BL      WDT_Init                        @ call C function              |
@ ---------------------------[ EVENT LOOP ]---------------------------------                              
loop                                                                       |
    @ while(1) loop     ---[ Reset WDT ]---                                |
    BL      WDT_Reset                       @ call C function              |
    B       loop                            @ branch back to loop start    |
@ ---------------------------[ END OF FILE ]--------------------------------