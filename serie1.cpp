/* ====================================
    Programación de Microprocesadores 
======================================= 
    Proyecto 3 - Euler.cpp
======================================= 
    Pablo Méndez 19195
    Diana corado
    Orlando Cabrera
    José Hurtarte 
======================================= 
*/


// ================ LIBRERÍAS =================
#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <cmath>
using namespace std;

// =================CONSTANTES =========================

// Cantidad de términos que se van a usar en el cálculo
#define N_TERMINOS 100
// El valor real de euler para porcentaje de error
#define REAL_EULER 2.71828182846

// ================ FUNCIONES ÚTILES ====================

/**
 * Función factoral
 * Cálcula el valor del factorial de un número
 * No es recursiva, pero podría ser.
 * 
 * @param numero - El número al que se le sacará el factorial
 * @return El valor del factorial del número
*/
long double factorial(int numero){
    long double resultado = 1;

    while(numero > 1){
        resultado *= numero;
        numero--;
    }

    return resultado;
}

// ====================== MAIN =======================

int main(){
    int i = 0;
    long double euler = 0;
    long double termino = 0;

    cout.precision(30);         // Para que imprima todos los decimales.

    // Hago un ciclo con paralelismo para que cada hilo cálcule el término
    #pragma omp for private (termino) 
    for(i = 0; i < N_TERMINOS; i++){
        // El valor de cada término es 1/n!
        termino = 1/factorial(i);
        cout << "Término " << i << ": "  << termino << endl;

        // Actualizo el resultado global
        #pragma omp atomic
        euler += termino;
    }

    cout << endl;
    cout << "El valor de euler calculado con los primeros " << N_TERMINOS << " términos es: " << euler << endl;

    cout.precision(3);
    cout << "El porcentaje de error fue de " << 100 * abs(euler - REAL_EULER) / REAL_EULER << "%" << endl;
    return 0;
}
