// mpic++ -g -Wall -o oes oddeven.cpp
// mpiexec -n 1 --oversubscribe ./oes

#include <iostream>
#include <mpi.h>
#include <algorithm>
#include <stdlib.h>

#define MAX 50000

using namespace std;

void Odd_even_sort(int a[],int n){
    int phase,i,temp;

    for(phase = 0; phase <n; phase++){
        if(phase%2==0){
            for(i=1;i<n;i+=2){
                if(a[i-1]>a[i]){
                    temp=a[i];
                    a[i]=a[i-1];
                    a[i-1]=temp;
                }
            }
        }
        else{
            for(i=1;i<n-1;i+=2){
                if(a[i]>a[i+1]){
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
            }
        }
    }
}


void printVector(int a[]){
    cout << endl;
    for(int i=0; i<MAX; i++){
        cout << a[i] << " - ";
    }
    cout << endl;
}


int main(){
    int comm_sz;
    int my_rank;
    double start,finish, t;

    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int* matrix = new int [MAX];
    srand(time(NULL));
    for(int i=0; i<MAX; i++){
        matrix[i] = rand( ) % MAX;
    }
    
    start = MPI_Wtime();
    Odd_even_sort(matrix,MAX);
    finish = MPI_Wtime();
    t = finish - start;
    //printVector(matrix);
    cout << t << endl;


    MPI_Finalize();
}