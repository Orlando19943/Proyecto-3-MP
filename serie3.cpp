/******************************************************************************
Universidad del Valle de Guatemala
Programacion de Microprocesadores
Catedratica: Kimberly Barrera
Proyecto 3: Serie 3
Orlando Cabrera 19943
Jose Javier Hurtarte 19707
Diana Corado 191025
Pablo Mendez 19195
*******************************************************************************/

#include <omp.h>					
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <unistd.h>  
#include <math.h>

using namespace std;
#define limite 100000                   //Simulacion de infinito
#define threads 100000                  //Hilos que trabajaran
int n = 1;                              //Inicio de la serie
double resultado = 0;                   //Resultado de la serie
//Funcion para realizar la operacion de la serie (1-1/√n)^n
double CalculoSerie3 (int p){
    double calculo = 1-(1/sqrt(p));         
    return pow (calculo,p);
}

int main()
{
    #pragma omp parallel private(n)
    {
        #ifdef _OPENMP
		omp_set_num_threads(threads);
		#endif
        #pragma omp for                 //Ciclo for para realizar el calculo de la serie
        for(n = 1;n<=limite;n++)
        {
            #pragma omp atomic update   //Seccion atomica para actualizar la variable "resultado" por todos los hilos
                resultado += CalculoSerie3(n); 
        }
        
    } 
    printf ("Resultado de la sumatoria = %f\n", resultado);
    
}

