#ifndef TESTORDENAMIENTO_H
#define TESTORDENAMIENTO_H

#include <vector>

void burbuja(int array[], int size, long long &comp, long long &inter);
void burbujaModificada(int arreglo[], int n, long long &comp, long long &inter);
void insercion(int array[], int size, long long &comp, long long &inter);
void seleccion(int array[], int size, long long &comp, long long &inter);
void shellsort(int array[], int size, long long &comp, long long &inter);
void swap(int array[], int a, int b);
void quickSort(int array[], int inicio, int fin, long long &comp, long long &inter);


#endif // TESTORDENAMIENTO_H