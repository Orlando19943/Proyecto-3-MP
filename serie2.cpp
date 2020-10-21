/*--------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* PROGRAMACION DE MICROPROCESADORES, CICLO 2, 2020
* PROYECTO 3 SERIE II
* Orlando Osberto Cabrera 	#19943
* Jose Javier Hurtarte		#19707
* Pablo Alejandro Mendez	#19195
* Diana Zaray Corado 		#191025	
* Fecha: 17/09/2020
* Valor de convergencia de la serie (1/(n*(n+1)
* --------------------------------------------------------*/

//Librerias 
#include <omp.h>					
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Constante para definir el numero de hilos a crear y el limite de la sumatoria
#define NTH 100000000

int main(){
	
	double sum = 0;//Guarda el resultado de la sumatoria
	int a = 0;
	
	#pragma omp parallel private(a)
	{
		//Modifica la cantidad de hilos a utilizar 
		#ifdef _OPENMP
		omp_set_num_threads(NTH);
		#endif
		
		//Cada hilo toma un valor de a y realiza la suma
		//Al final los resultados obtenidos por cada hilo se reducen en uno solo
		//por medio de una suma.
		#pragma omp for reduction(+:sum)
		for(a = 1;a<NTH;a++){
			sum+= (1.0/(pow(a,2)+a));
		}
	
	}  
    printf("La sumatoria converge a = %f\n",sum);
    return 0;
} 
