/*******************************************************************************
Archivo:         SEMAFORO para PIC16F887
Dispositivo:     PIC16F887
Autor:           Sergio Vasquez
Compilador:      XC8, MPLABX 6.00
Creado:          10/04/2023
Ultima modificacion: 11/04/2023
*******************************************************************************/

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF       
#pragma config PWRTE = OFF      
#pragma config MCLRE = OFF      
#pragma config CP = OFF         
#pragma config CPD = OFF        
#pragma config BOREN = OFF      
#pragma config IESO = OFF       
#pragma config FCMEN = OFF      
#pragma config LVP = OFF        

// CONFIG2
#pragma config BOR4V = BOR40V   
#pragma config WRT = OFF        
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

//******************************************************************************
// Includes
//******************************************************************************
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>    

//******************************************************************************
// Definiciones
//******************************************************************************
#define _XTAL_FREQ 4000000  //Se establece el oscilador a 4.0Mhz
         
// Pines designados para cada color de LUZ o LED
#define LUZ_ROJA RB0       
#define LUZ_AMARILLA RB1    
#define LUZ_VERDE RB2       

void main(void) {
    TRISB = 0;  // Configura todos los pines del PORTB como salida
    PORTB = 0;  // Inicialmente todos los LEDs estan apagados
    
    while(1) {
        LUZ_ROJA = 1;       // Enciende el LED Rojo
        __delay_ms(5000);   // Delay de 20 segundos
        LUZ_ROJA = 0;       // Apaga el LED Rojo
        
        LUZ_AMARILLA = 1;   // Enciende el LED Amarillo
        __delay_ms(3000);   // Delay de 12 segundos
        LUZ_AMARILLA = 0;   // Apaga el LED Amarillo
        
        LUZ_VERDE = 1;      // Enciende el LED Verde
        __delay_ms(5000);   // Delay de 20 segundos
        LUZ_VERDE = 0;      // Apaga el LED Verde
    }
}
