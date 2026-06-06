#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include "testOrdenamiento.h"
#include <algorithm>

/*
\\Grupo:
Christopher Lara
Sebastian Quintana
Alfredo díaz
Keymers Campos 
*/

using namespace std;

// --- ESTRUCTURA DE RESULTADOS ---
struct ResultadosAlgoritmo {
    string nombre;
    
    // Tiempos (segundos)
    double tDesordenado = 0, tOrdenado = 0, tInvertido = 0;
    
    // Comparaciones
    long long cDesordenado = 0, cOrdenado = 0, cInvertido = 0;
    
    // Intercambios
    long long iDesordenado = 0, iOrdenado = 0, iInvertido = 0;
};

// --- FUNCIONES AUXILIARES SIMPLES ---
void copiarArreglo(const int origen[], int destino[], int size) {
    for (int i = 0; i < size; i++) {
        destino[i] = origen[i];
    }
}

int main() {
    const int SIZE = 30000;
    cout << "Generando arreglos base de " << SIZE << " elementos...\n\n";

    // Usamos memoria dinámica (new) porque 4 arreglos de 30000 enteros 
    // pueden desbordar la memoria estática (Stack Overflow) en algunos compiladores.
    int* arrOrdenado = new int[SIZE];
    int* arrInvertido = new int[SIZE];
    int* arrDesordenado = new int[SIZE];
    int* arrPrueba = new int[SIZE]; // Arreglo de trabajo para no dañar los originales

    // 1. Generar Arreglo Ordenado (1, 2, 3 ... 30000)
    for (int i = 0; i < SIZE; i++) {
        arrOrdenado[i] = i + 1;
    }

    // 2. Generar Arreglo Invertido (30000, 29999 ... 1)
    for (int i = 0; i < SIZE; i++) {
        arrInvertido[i] = arrOrdenado[SIZE - 1 - i];
    }

    // 3. Generar Arreglo Desordenado (Copiamos el ordenado y lo mezclamos aleatoriamente)
    copiarArreglo(arrOrdenado, arrDesordenado, SIZE);
    random_device rd;
    mt19937 generador(rd());
    shuffle(arrDesordenado, arrDesordenado + SIZE, generador);

    // Arreglo para guardar la información de los 6 algoritmos
    vector<ResultadosAlgoritmo> resultados(6);
    
    // Variables temporales para medir en cada bloque
    long long comp = 0, inter = 0;
    chrono::time_point<chrono::high_resolution_clock> inicio, fin;

    cout << "Iniciando pruebas de rendimiento (Esto tomara varios minutos)...\n";

    
    // 1. ALGORITMO: BURBUJA
    
    resultados[0].nombre = "Burbuja";
    cout << "Evaluando: " << resultados[0].nombre << "...\n";

    // -> Burbuja: Desordenado
    copiarArreglo(arrDesordenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    burbuja(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[0].tDesordenado = chrono::duration<double>(fin - inicio).count();
    resultados[0].cDesordenado = comp;
    resultados[0].iDesordenado = inter;

    // -> Burbuja: Ordenado
    copiarArreglo(arrOrdenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    burbuja(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[0].tOrdenado = chrono::duration<double>(fin - inicio).count();
    resultados[0].cOrdenado = comp;
    resultados[0].iOrdenado = inter;

    // -> Burbuja: Invertido
    copiarArreglo(arrInvertido, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    burbuja(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[0].tInvertido = chrono::duration<double>(fin - inicio).count();
    resultados[0].cInvertido = comp;
    resultados[0].iInvertido = inter;


    
    // 2. ALGORITMO: BURBUJA MODIFICADA
    
    resultados[1].nombre = "Burbuja Modificada";
    cout << "Evaluando: " << resultados[1].nombre << "...\n";

    // -> Burbuja Mod: Desordenado
    copiarArreglo(arrDesordenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    burbujaModificada(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[1].tDesordenado = chrono::duration<double>(fin - inicio).count();
    resultados[1].cDesordenado = comp;
    resultados[1].iDesordenado = inter;

    // -> Burbuja Mod: Ordenado
    copiarArreglo(arrOrdenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    burbujaModificada(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[1].tOrdenado = chrono::duration<double>(fin - inicio).count();
    resultados[1].cOrdenado = comp;
    resultados[1].iOrdenado = inter;

    // -> Burbuja Mod: Invertido
    copiarArreglo(arrInvertido, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    burbujaModificada(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[1].tInvertido = chrono::duration<double>(fin - inicio).count();
    resultados[1].cInvertido = comp;
    resultados[1].iInvertido = inter;


    
    // 3. ALGORITMO: INSERCION
    
    resultados[2].nombre = "Insercion";
    cout << "Evaluando: " << resultados[2].nombre << "...\n";

    copiarArreglo(arrDesordenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    insercion(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[2].tDesordenado = chrono::duration<double>(fin - inicio).count();
    resultados[2].cDesordenado = comp;
    resultados[2].iDesordenado = inter;

    copiarArreglo(arrOrdenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    insercion(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[2].tOrdenado = chrono::duration<double>(fin - inicio).count();
    resultados[2].cOrdenado = comp;
    resultados[2].iOrdenado = inter;

    copiarArreglo(arrInvertido, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    insercion(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[2].tInvertido = chrono::duration<double>(fin - inicio).count();
    resultados[2].cInvertido = comp;
    resultados[2].iInvertido = inter;


    
    // 4. ALGORITMO: SELECCION
    
    resultados[3].nombre = "Seleccion";
    cout << "Evaluando: " << resultados[3].nombre << "...\n";

    copiarArreglo(arrDesordenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    seleccion(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[3].tDesordenado = chrono::duration<double>(fin - inicio).count();
    resultados[3].cDesordenado = comp;
    resultados[3].iDesordenado = inter;

    copiarArreglo(arrOrdenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    seleccion(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[3].tOrdenado = chrono::duration<double>(fin - inicio).count();
    resultados[3].cOrdenado = comp;
    resultados[3].iOrdenado = inter;

    copiarArreglo(arrInvertido, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    seleccion(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[3].tInvertido = chrono::duration<double>(fin - inicio).count();
    resultados[3].cInvertido = comp;
    resultados[3].iInvertido = inter;


    
    // 5. ALGORITMO: SHELLSORT
    
    resultados[4].nombre = "Shellsort";
    cout << "Evaluando: " << resultados[4].nombre << "...\n";

    copiarArreglo(arrDesordenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    shellsort(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[4].tDesordenado = chrono::duration<double>(fin - inicio).count();
    resultados[4].cDesordenado = comp;
    resultados[4].iDesordenado = inter;

    copiarArreglo(arrOrdenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    shellsort(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[4].tOrdenado = chrono::duration<double>(fin - inicio).count();
    resultados[4].cOrdenado = comp;
    resultados[4].iOrdenado = inter;

    copiarArreglo(arrInvertido, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    shellsort(arrPrueba, SIZE, comp, inter);
    fin = chrono::high_resolution_clock::now();
    resultados[4].tInvertido = chrono::duration<double>(fin - inicio).count();
    resultados[4].cInvertido = comp;
    resultados[4].iInvertido = inter;


    
    // 6. ALGORITMO: QUICKSORT
    
    resultados[5].nombre = "Quicksort";
    cout << "Evaluando: " << resultados[5].nombre << "...\n";

    copiarArreglo(arrDesordenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    // Cambiamos SIZE por 0 y SIZE - 1
    quickSort(arrPrueba, 0, SIZE - 1, comp, inter); 
    fin = chrono::high_resolution_clock::now();
    resultados[5].tDesordenado = chrono::duration<double>(fin - inicio).count();
    resultados[5].cDesordenado = comp;
    resultados[5].iDesordenado = inter;

    copiarArreglo(arrOrdenado, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    quickSort(arrPrueba, 0, SIZE - 1, comp, inter); 
    fin = chrono::high_resolution_clock::now();
    resultados[5].tOrdenado = chrono::duration<double>(fin - inicio).count();
    resultados[5].cOrdenado = comp;
    resultados[5].iOrdenado = inter;

    copiarArreglo(arrInvertido, arrPrueba, SIZE);
    comp = 0; inter = 0;
    inicio = chrono::high_resolution_clock::now();
    quickSort(arrPrueba, 0, SIZE - 1, comp, inter); 
    fin = chrono::high_resolution_clock::now();
    resultados[5].tInvertido = chrono::duration<double>(fin - inicio).count();
    resultados[5].cInvertido = comp;
    resultados[5].iInvertido = inter;

    cout << "\n¡Todas las pruebas han finalizado!\n\n";

    // Liberar la memoria de los arreglos dinámicos
    delete[] arrOrdenado;
    delete[] arrInvertido;
    delete[] arrDesordenado;
    delete[] arrPrueba;

    
    // IMPRESIÓN DE RESULTADOS (EJEMPLO TABLA DE TIEMPOS)
    
    cout << "---------------------------------------------------------\n";
    cout << "            TABLA DE TIEMPOS (Segundos)                  \n";
    cout << "---------------------------------------------------------\n";
    cout << "Metodo" 
         << "Desordenado" 
         << "Ordenado" 
         << "Invertido\n";
    cout << "---------------------------------------------------------\n";
    
    for (int i = 0; i < 6; i++) {
        cout << resultados[i].nombre << "\t" << resultados[i].tDesordenado << "\t" << resultados[i].tOrdenado << "\t" << resultados[i].tInvertido << "\n";
    }

  
    int opcion;
    do {
        cout << "\n--- MENU DE RESULTADOS ---" << endl;
        cout << "1. Ver Tabla de Tiempos" << endl;
        cout << "2. Ver Tabla de Comparaciones" << endl;
        cout << "3. Ver Tabla de Intercambios" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion; 

        switch (opcion) {
            case 1:
                cout << "\n--- TABLA DE TIEMPOS ---\n";
                cout << "Algoritmo\t" << "Desordenado\t" << "Ordenado\t" << "Invertido\n";
                for (const auto& r : resultados) {
                    cout << r.nombre << "\t" << r.tDesordenado << "\t" << r.tOrdenado << "\t" << r.tInvertido << "\n";
                }
                break;

            case 2:
                cout << "\n--- TABLA DE COMPARACIONES ---\n";
                cout << "Algoritmo\t" << "Desordenado\t" << "Ordenado\t" << "Invertido\n";
                for (const auto& r : resultados) {
                    cout << r.nombre << "\t" << r.cDesordenado << "\t" << r.cOrdenado << "\t" << r.cInvertido << "\n";
                }
                break;

            case 3:
                cout << "\n--- TABLA DE INTERCAMBIOS ---\n";
                cout << "Algoritmo\t" << "Desordenado\t" << "Ordenado\t" << "Invertido\n";
                for (const auto& r : resultados) {
                    cout << r.nombre << "\t" << r.iDesordenado << "\t" << r.iOrdenado << "\t" << r.iInvertido << "\n";
                }
                break;

            case 4:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 4);

    return 0;
}