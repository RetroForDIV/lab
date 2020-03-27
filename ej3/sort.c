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
         if (izq < der){
            pivot = partition(a, izq, der);
            if (izq < pivot){
            quick_sort_rec(a, izq, pivot-1);
            }
            if (pivot < der)
            {
            quick_sort_rec(a, pivot+1, der);
            }
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}



//     gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie -c array_helpers.c sort.c
//     gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie -o sorter *.o main
//     ./sorter input/example-unsorted.in

/*
proc partition (in/out a: array[1..n] of T, in lft, rgt: nat, out ppiv: nat)
var i,j: nat
ppiv:= lft
i:= lft+1
j:= rgt
do i ≤ j ! if a[i] ≤ a[ppiv] ! i:= i+1
a[j] ≥ a[ppiv] ! j:= j-1
a[i] > a[ppiv] ^ a[j] < a[ppiv] ! swap(a,i,j)
i:= i+1
j:= j-1
fi
od
swap(a,ppiv,j) {dejando el pivot en una posición más central}
ppiv:= j {señalando la nueva posición del pivot }
end proc

unsigned int merge(int * c, unsigned int lft, unsigned int rgt) f
unsigned int ppiv = lft;
unsigned int i = lft+1;
unsigned int j = rgt-1;
while (i <= j) f
if (c[i] <= c[ppiv]) i++;
else if (c[j] >= c[ppiv]) j- -;
else f
swap(c,i,j);
i++; j- -;
g
g
swap(c,ppiv,j);
ppiv = j;
return ppiv;


void qsort(int * b, unsigned int lft, unsigned int rgt) f
if (lft + 1 < rgt) f
unsigned int ppiv = partition(b,lft,rgt);
qsort(b,lft,ppiv);
qsort(b,ppiv+1,rgt);
g
g

unsigned int partition(int * c, unsigned int lft, unsigned int rgt) f
unsigned int ppiv = lft;
unsigned int i = lft+1;
unsigned int j = rgt;
while (i <= j) f
if (c[i] <= c[ppiv]) i++;
else if (c[j] >= c[ppiv]) j- -;
else f
swap(c,i,j);
i++; j- -;
g
g
swap(c,ppiv,j);
ppiv = j;
return ppiv;
g

*/

    /* Needs implementation */

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */