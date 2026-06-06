#include <iostream>
#include "testOrdenamiento.h"

using namespace std;

void burbuja(int array[], int size, long long &comp, long long &inter) {
    int i, j;
    for (i = 1; i < size; i++) {
        for (j = size - 1; j >= i; --j) {
            comp++;
            if (array[j - 1] > array[j]) {
                inter++;
                int t = array[j - 1];
                array[j - 1] = array[j];
                array[j] = t;
            }
        }
    }
}

void burbujaModificada(int arreglo[], int n, long long &comp, long long &inter) {
    bool intercambiado;
    for (int i = 0; i < n - 1; i++) {
        intercambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arreglo[j] > arreglo[j + 1]) {
                inter++;
                int temporal = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temporal;
                intercambiado = true;
            }
        }
        if (!intercambiado) break;
    }
}

void insercion(int array[], int size, long long &comp, long long &inter) {
    int i, j;
    for (i = 1; i < size; i++) {
        for (j = i; j > 0; j--) {
            comp++; // Se cuenta la comparacion del if (o la que estaria en el for)
            if (array[j] < array[j - 1]) {
                inter++;
                int t = array[j];
                array[j] = array[j - 1];
                array[j - 1] = t;
            } else {
                break; // Si ya esta ordenado, no sigue comparando hacia atras
            }
        }
    }
}

void seleccion(int array[], int size, long long &comp, long long &inter) {
    int e, i, j;
    for (i = 0; i < size - 1; i++) {
        e = i;
        for (j = i + 1; j < size; j++) {
            comp++;
            if (array[e] > array[j]) {
                e = j;
            }
        }
        if (i != e) {
            inter++;
            int t = array[i];
            array[i] = array[e];
            array[e] = t;
        }
    }
}

void shellsort(int array[], int size, long long &comp, long long &inter) {
    int gap, i, j;
    for (gap = size / 2; gap > 0; gap /= 2) {
        for (i = gap; i < size; i++) {
            for (j = i - gap; j >= 0; j -= gap) {
                comp++;
                if (array[j + gap] < array[j]) {
                    inter++;
                    int t = array[j];
                    array[j] = array[j + gap];
                    array[j + gap] = t;
                } else {
                    break;
                }
            }
        }
    }
}

// Función swap (Asegúrate de mantenerla con el contador)
void swap(int array[], int a, int b, long long &inter) {
    inter++;
    int t = array[b];
    array[b] = array[a];
    array[a] = t;
}

// QuickSort unificado (Partición + Recursividad)
void quickSort(int array[], int inicio, int fin, long long &comp, long long &inter) {
    // Condición de parada de la recursividad
    if (inicio >= fin) {
        return; 
    }

    int pivote = array[inicio];
    int inferior = inicio + 1;
    int superior = fin;
    
    do {
        while (inferior <= superior) {
            comp++;
            if (array[inferior] > pivote) break;
            inferior++;
        }
        while (inferior <= superior) {
            comp++;
            if (array[superior] <= pivote) break;
            superior--;
        }
        if (inferior <= superior) {
            swap(array, inferior, superior, inter);
            inferior++;
            superior--;
        }
    } while (inferior <= superior);
    
    swap(array, inicio, superior, inter);
    
    // Llamadas recursivas para ordenar la mitad izquierda y derecha
    quickSort(array, inicio, superior - 1, comp, inter);
    quickSort(array, superior + 1, fin, comp, inter);
}


