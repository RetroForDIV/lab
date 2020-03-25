#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


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




//gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c
//gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sorter *.o main
//./sorter input/example-unsorted.in

/*   

proc insertion_sort (in/out a: array[1..n] of T)
for i:= 2 to n do
insert(a,i)
od
end proc
proc insert (in/out a: array[1..n] of T, in i: nat)
var j: nat
j:= i
do j > 1 ^ a[j] < a[j − 1] ! swap(a,j-1,j)
j:= j-1
od
end proc


 */




