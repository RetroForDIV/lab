#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der)  {

    unsigned int i,j,pivot;

    pivot = izq;
    i = izq+1;
    j = der;
    
    while (i <= j) {

        if (goes_before(a[i], a[pivot])){
                i++;
        }
        else if (goes_before(a[pivot], a[j])){
                j--;
        }
        else {
                swap(a,i,j);
                i++;
                j--;
        }
    }

    swap(a,pivot,j);
    pivot = j;

    return (pivot);
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {

    unsigned int pivot;
         if (izq +1 < der){
            pivot = partition(a, izq, der);
            quick_sort_rec(a, izq, pivot);
            quick_sort_rec(a, pivot+1, der);
            }
    }


void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}



//     gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie -c array_helpers.c sort.c
//     gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie -o sorter *.o main
//     ./sorter input/example-unsorted.in

    /* Needs implementation */

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */