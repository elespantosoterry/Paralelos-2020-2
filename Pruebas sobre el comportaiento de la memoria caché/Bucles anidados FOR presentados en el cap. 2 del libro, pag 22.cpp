#include <iostream>
#include <string>
#include <ctime> 
using namespace std;

#define MAX 5000

int main() {

    // =======================
    // CREACION E INICIALIZACION DE MATRICES DINÁMICAS
    // =======================
       
    int** A = new int*[MAX];
    int* x = new int [MAX];
    int* y = new int [MAX];
   

    for (int i = 0; i < MAX; i++)
        A[i] = new int[MAX];


    for (int i = 0; i < MAX; i++) {
        x[i] = i / 10;
        y[i] = 0;
        A[i][i] = i / 9;
    }

    // =======================
    // PRIMER BUCLE
    // =======================

    unsigned t0, t1;

    t0 = clock();

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j];

    t1 = clock();

    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Tiempo de Ejecución: " << time << endl;

    // =======================
    // SEGUNDO BUCLE
    // =======================

    t0 = clock();

    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j] * x[j];

    t1 = clock();

    time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Tiempo de Ejecución: " << time << endl;
}