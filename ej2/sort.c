#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"



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



 /* 

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

--------------------------------------------------------------------------

unsigned int partition(int a[], unsigned int izq, unsigned int der);

 Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]

//     gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie -c array_helpers.c sort.c
//     gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie -o sorter *.o main
//     ./sorter input/example-unsorted.in


*/



