#include <iostream>
#include <string>
#include <ctime> 
using namespace std;

#define MAX 1000

void multiplicacionClasica(double** m1, double** m2, double** res){

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            res[i][j] = 0;
            for (int k = 0; k < MAX; k++)
                res[i][j] += m1[i][k] * m2[k][j];
        }
    }
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

    multiplicacionClasica(A, B, res);

    t1 = clock();

    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Tiempo de Ejecución: " << time << endl;

}