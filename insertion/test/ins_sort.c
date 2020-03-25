#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


void insert(int array[], unsigned int i) {
    unsigned int j = i;

    if (goes_before(array[j], array[j-1])){
           
        swap(array,j,j-1);

        j = j-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


//gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c
//gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sorter *.o main