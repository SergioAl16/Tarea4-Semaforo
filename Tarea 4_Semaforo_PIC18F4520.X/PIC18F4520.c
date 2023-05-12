/*******************************************************************************
Archivo:         SEMAFORO para PIC18F4520
Dispositivo:     PIC18F4520
Autor:           Sergio Vasquez
Compilador:      XC8, MPLABX 6.00
Creado:          10/04/2023
Ultima modificacion: 11/04/2023
*******************************************************************************/

#include <xc.h>

//CONFIGURACIONES DEL PIC
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF
#pragma config MCLRE = OFF

#define _XTAL_FREQ 20000000  //Define la frecuencia del cristal

// Pines designados para cada color de LUZ o LED
#define LUZ_ROJA RB0       
#define LUZ_AMARILLA RB1    
#define LUZ_VERDE RB2       

void main(void) {
    TRISB = 0;  // Configura todos los pines del PORTB como salida
    PORTB = 0;  // Inicialmente todos los LEDs estan apagados
    
    while(1) {
        LUZ_ROJA = 1;       // Enciende el LED Rojo
        __delay_ms(5000);   // Delay de +20 segundos
        LUZ_ROJA = 0;       // Apaga el LED Rojo
        
        LUZ_AMARILLA = 1;   // Enciende el LED Amarillo
        __delay_ms(3000);   // Delay de +12 segundos
        LUZ_AMARILLA = 0;   // Apaga el LED Amarillo
        
        LUZ_VERDE = 1;      // Enciende el LED Verde
        __delay_ms(5000);   // Delay de +20 segundos
        LUZ_VERDE = 0;      // Apaga el LED Verde
    }
}

