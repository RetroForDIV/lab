#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    if (goes_before(der, izq)){
        partition(a, izq, der);
        quick_sort_rec(a, izq, pivot-1);
        quick_sort_rec(a, pivot+1, der);
    
    }
}
 /* 
 
    needs implementation 

     no implementes partition, ya está implementado en sort_helpers.o
       (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}




void insert(int array[], unsigned int i) {
    unsigned int j;
    for (j = i; (goes_before(array[j], array[j-1])); j--) {
           
        swap(array,j-1,j);
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


unsigned int partition(int a[], unsigned int izq, unsigned int der);
 Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before)
      a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]

proc quick_sort_rec (in/out a: array[1..n] of T, in lft,rgt: nat)
var ppiv: nat
if rgt > lft ! partition(a,lft,rgt,ppiv)
lft ≤ ppiv ≤ rgt
elementos en a[lft,ppiv-1] ≤ a[ppiv]
elementos en a[ppiv+1,rgt] ≥ a[ppiv]}
quick_sort_rec(a,lft,ppiv-1)
quick_sort_rec(a,ppiv+1,rgt)
fi
end proc

*/


