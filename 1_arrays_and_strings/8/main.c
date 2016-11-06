// Write an algorithm such that if an element
// in an MxN matrix is 0, its entire row and
// column are set to 0.

#include <stdio.h>
#include <stdlib.h>

void print_matrix(char *matrix, int size) {
    for(int i = 0; i < size*size; i++) {
        printf("%c ", matrix[i]);
        if((i+1) % size == 0) {
            printf("\n");
        }
    }
}

void copy_matix(char *dst, char *src, int size) {
    for(int i = 0; i < size*size; i++) {
        dst[i] = src[i];
    }
}

void zero_matrix(char *matrix, int size) {
    char old[size*size];
    copy_matix(old, matrix, size);
    for(int i = 0; i < size*size; i++) {
        if(old[i] == '0') {
            for(int j = 0; j < size; j++) {

                matrix[(i/size)*size + j] = '0';
                matrix[j*size + i%size] = '0';
            }
        }
    }
}

int main() {

    char matrix[16] = {
        '1', '2', '3', '4',
        '5', '6', '7', '8',
        'c', 'd', 'e', 'f',
        '9', '0', 'a', 'b',
    };
    
    printf("Before:\n");
    print_matrix(matrix, 4);

    zero_matrix(matrix, 4);

    printf("After:\n");
    print_matrix(matrix, 4);

}