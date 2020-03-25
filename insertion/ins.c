#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 10

void swap(int array[], unsigned int i, unsigned int j){
int tmp;

tmp = array[i];
array[i] = array[j];
array[j] = tmp;

}

void insert(int array[], unsigned int i) {
    array = array;
    unsigned int j = i;
    while (j > 0 && array[j] < array[j-1]) {
        swap(array,j,j-1);
        j = j-1;
    }
}

int main() {

printf("\ninsertion sort:\n\n");


    int array[ARRAY_SIZE] = { 4, -1, 5, 8, 9, 0, 3, 6, 0, 0 };

    // PEDIR AL USUARIO QUE INGRESE LOS ELEMENTOS DEL ARREGLO.
    int i;
    for(i=0; i<ARRAY_SIZE;i++){
        int valor=0;
        printf("Ingrese el elemento %d del arreglo\n", i);
        scanf("%d",&valor);
        array[i]= valor;
    }

for (unsigned int i; i < ARRAY_SIZE; i++) {   
    insert(array,i);
        }

        printf("el arreglo ordenado es:\n");
        for (i = 0; i < ARRAY_SIZE; i++){
            printf( "%d ", array[i]) ;
        }
        
    printf("\n");

}


//upload


