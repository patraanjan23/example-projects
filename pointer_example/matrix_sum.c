#include <stdio.h>
#define SIZE 3

/* fn prototype */
void print_arr(int *, int);
void sum_arr(int *, int *, int *, int);

int main(void) {
    
    /* declration */
    int i, j;
    int array_1[SIZE][SIZE], array_2[SIZE][SIZE];
    
    /* THIS IS IMPORTANT */
    int result[SIZE][SIZE]; 
    
    /* filling array */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            array_1[i][j] = i + j + 1; /* just an example value */
            array_2[i][j] = i * j + 1; /* just an example value */
        }
    }
    
    /* printing the arrays */
    printf("matrix 1\n");
    print_arr((int *)array_1, SIZE); /* typecasting 2D array ptr to a int ptr: (int *) */
    
    printf("matrix 2\n");
    print_arr((int *)array_2, SIZE); /* typecasting 2D array ptr to a int ptr: (int *) */
    
    /* calling the sum fn */
    sum_arr((int*)array_1, (int*)array_2, (int*)result, SIZE);
    printf("sum of the 2 matrices:\n");
    print_arr((int*)result, SIZE);

    return 0;
}

void print_arr(int *array, int sz) {
    int i, j;
    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz; j++) {
            /*
             * array[i][j] is in the memory location array+i*sz + j
             * so dereferencing that location
             * 
             * example: 
             * a = {{1, 2}, {3, 4}, {5, 6}};
             * 
             * a is stored in the memory as 1, 2, 3, 4, 5, 6
             * 
             * following are corresponding memory location for each element:
             * 1 -> a + 0 = a + 0 * 2 + 0
             * 2 -> a + 1 = a + 0 * 2 + 1
             * 3 -> a + 2 = a + 1 * 2 + 0
             * 4 -> a + 3 = a + 1 * 2 + 1
             * 5 -> a + 4 = a + 2 * 2 + 0
             * 6 -> a + 5 = a + 2 * 2 + 1
             * 
             * a is the memory location of the 1st element.
             * 
             * basically, array[i][j] == *((array + i * sz) + j)
             */
            printf("%d ", *((array + i * sz) + j));
        }
        printf("\n");
    }
}

void sum_arr(int *a, int *b, int *result, int sz) {
    int i, j;
    int tmp_a_element, tmp_b_element; /* for sanity */
    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz; j++) {
            /* taking a[i][j] and b[i][j] in tmp variables for ease */
            tmp_a_element = *((a + i * sz) +j);
            tmp_b_element = *((b + i * sz) +j);
            
            /* setting result[i][j] = a[i][j] + b[i][j] */
            *((result + i * sz) + j) = tmp_a_element + tmp_b_element;
            
            /* IMPORTANT: You need to have a result array declared with proper dimensions 
             * outside the function for this to work. If you want to create an array inside
             * function and return it, you cannot do that without using malloc,
             * which is even more complicated.
             */
        }
    }
}
