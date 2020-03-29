#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


void insert(int a[], unsigned int i) {
    unsigned int j;
    for (j = i; j > 0 ; j-- ) {
       if (goes_before(a[j], a[j-1])){    
        swap(a,j,j-1);
       }
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
 
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

