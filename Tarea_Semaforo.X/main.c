/*******************************************************************************
Archivo:         Tarea Semaforo
Dispositivo:     PIC16F887
Autor:           Sergio Vasquez
Compilador:      XC8, MPLABX 6.00
Creado:          8/05/2023
Ultima modificacion: 10/05/2023
*******************************************************************************/
//TX = c6
//RX = c7

//**************************
// Includes
//**************************
#include <xc.h> // Incluir el archivo de cabecera para el PIC16F887

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

// Definición de frecuencia de oscilador y velocidad de transmisión serial
#define _XTAL_FREQ 8000000

// Definimos los pines del semáforo
#define GREEN_LED RD2
#define YELLOW_LED RD1
#define RED_LED RD0

// Definimos el tiempo de duración de cada estado del semáforo
#define GREEN_TIME 5000
#define YELLOW_TIME 1000
#define RED_TIME 5000

// Función para detener el programa durante un tiempo específico en milisegundos
void delay_ms(unsigned int ms) {
    for (unsigned int i = 0; i < ms; i++) {
        __delay_ms(1);
    }
}

// Función para encender el LED verde y apagar los demás
void green_on() {
    GREEN_LED = 1;
    YELLOW_LED = 0;
    RED_LED = 0;
}

// Función para encender el LED amarillo y apagar los demás
void yellow_on() {
    GREEN_LED = 0;
    YELLOW_LED = 1;
    RED_LED = 0;
}

// Función para encender el LED rojo y apagar los demás
void red_on() {
    GREEN_LED = 0;
    YELLOW_LED = 0;
    RED_LED = 1;
}

void main(void) {
    TRISD = 0x00; // Configuramos el puerto D como salida
    
    while (1) { // Ciclo infinito
        green_on(); // El semáforo comienza en verde
        delay_ms(GREEN_TIME);
        
        yellow_on(); // El semáforo cambia a amarillo
        delay_ms(YELLOW_TIME);
        
        red_on(); // El semáforo cambia a rojo
        delay_ms(RED_TIME);
        
        yellow_on(); // El semáforo cambia a amarillo nuevamente
        delay_ms(YELLOW_TIME);
    }
}
