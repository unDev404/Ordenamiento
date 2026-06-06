#include <iostream>
#include "testOrdenamiento.h"

using namespace std;   


void burbuja(int array[],int size)
{
int i,j;
for(i=1;i<size;i++)
 for(j=size-1;j>=i;--j)
 if(array[j-1]>array[j]){
 int t; // intercambio
t=array[j-1];
array[j-1]=array[j];
 array[j]=t;
 }
}


void burbujaModificada(int arreglo[], int n) {
    bool intercambiado;
    
    for (int i = 0; i < n - 1; i++) {
        intercambiado = false; // Se reinicia la bandera en cada pasada
        
        // Los últimos 'i' elementos ya están en su lugar correcto
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambio manual de variables
                int temporal = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temporal;
                
                intercambiado = true; // Hubo al menos un intercambio
            }
        }
        
        // Si no hubo ningún intercambio en la pasada interior, 
        // significa que el arreglo ya está ordenado.
        if (!intercambiado) {
            break; // Rompemos el ciclo para ahorrar tiempo de ejecución
        }
    }
}


void insercion(int array[],int size)
{
 int i,j;
 for(i=2;i<size;i++){
 for(j=i; j>0 && array[j]<array[j-1]; j--){
 int t; // Intercambiar
t=array[j];
array[j]=array[j-1];
 array[j-1]=t;
 }
}
}


void seleccion(int array[],int size)
{
 int e,i,j;
 for(i=0; i<size-1; i++){
 e=i;
 for(j=i+1; j<size; j++)
 if(array[e]>array[j])
 e=j;
if(i!=e){
int t; // intercambiar
t=array[i];
 array[i]=array[e];
 array[e]=t;
 }
 }
}


void shellsort(int array[],int size){
int gap,i,j;
for(gap=size/2;gap>0;gap/=2)
for(i=gap;i<size;i++)
for(j=i-gap; j>=0 && array[j+gap]<array[j]; j-=gap){
int t; // Intercambiar
t=array[j];
array[j]=array[j+gap];
array[j+gap]=t;
}
}

//para el Quicksort
void swap(int array[], int a,int b){
int t;
t=array[b];
array[b]=array[a];
array[a]=t;
}

//Quicksort
int quickSort(int array[], int inicio, int fin){
int pivote, inferior=inicio+1, superior=fin;
pivote=array[inicio];
do{
while(array[inferior]<=pivote && inferior<=superior)
inferior++;
while(array[superior]>pivote && inferior<=superior)
superior--;
if(inferior <= superior){
swap(array,inferior,superior);
inferior++;
superior--;
}
}while(inferior<=superior);
swap(array,inicio,superior);
return superior;
}



