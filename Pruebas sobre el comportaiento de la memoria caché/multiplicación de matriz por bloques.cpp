#include <iostream>
#include <string>
#include <ctime> 
using namespace std;

#define MAX 1000

void multiplicacionBloques( double** a, double** b, double** c)
{   
    int n = MAX;
    int blockSize = 50;

    for (int bi = 0; bi < n; bi += blockSize)
        for (int bj = 0; bj < n; bj += blockSize)
            for (int bk = 0; bk < n; bk += blockSize)
                for (int i = 0; i < blockSize; i++)
                    for (int j = 0; j < blockSize; j++)
                        for (int k = 0; k < blockSize; k++)
                            c[bi + i][bj + j] += a[bi + i][bk + k] * b[bk + k][bj + j];
}

int main() {

    // =======================
    // CREACION E INICIALIZACION DE MATRICES DINÁMICAS
    // =======================
       
    double** A = new double*[MAX];
    double** B = new double* [MAX];
    double** res = new double* [MAX];

   

    for (int i = 0; i < MAX; i++) {
        A[i] = new double[MAX];
        B[i] = new double[MAX];
        res[i] = new double[MAX];
    }


    for (int i = 0; i < MAX; i++) {
        res[i][i] = 1 / 6;
        B[i][i] = 1 / 8;
        A[i][i] = i / 9;
    }

    // =======================
    // EJECUCIÓN
    // =======================

    unsigned t0, t1;

    t0 = clock();

    multiplicacionBloques(A, B, res);

    t1 = clock();

    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Tiempo de Ejecución: " << time << endl;

}