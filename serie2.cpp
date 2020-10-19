/*--------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* PROYECTO 3 SERIE II
*
* Author: Diana Zaray Corado Lopez #191025
* Fecha: 17/09/2020
* Valor de convergencia de la serie (1/(n*(n+1)
* --------------------------------------------------------*/

#include <omp.h>					
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	
	float sum = 0.00;
	int nth = 10000000;
	
	#pragma omp parallel
	{
		#ifdef _OPENMP
		omp_set_num_threads(nth);
		#endif
		#pragma omp parallel for reduction(+:sum)
		for(int a=1;a<nth;a++){
			sum+= (1.0/(pow(a,2)+a));
		}
	
	}  
    printf("La sumatoria converge a = %0.11f\n",sum);
    return 0;
} 
