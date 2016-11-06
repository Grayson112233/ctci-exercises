// Given an image represented by an NxN matrix, where each pixel
// in the image is 4 bytes, write a method to rotate the image by
// 90 degrees. (an you do this in place?

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

// This solution moves 4 pixels at a time,
// moving in an inward spiraling pattern
void rotate(char *matrix, int size) {
	for(int i = 0; i < size/2; i++) {
		for(int j = 0; j < (size-(i*2))-1; j++) {
			// Top left: [i][i+j]
			char *top_left = matrix + (i*size + j+i);
			// Top right: [i+j][size-i-1]
			char *top_right = matrix + ((i+j)*size + size-i-1);
			// Bottom right: [size-i-1][size-i-j-1]
			char *bottom_right = matrix + ((size-i-1)*size + size-i-j-1);
			// Bottom left: [size-i-j-1][i]
			char *bottom_left = matrix + ((size-i-j-1)*size + i);

			char temp = *top_left;
			*top_left = *bottom_left;
			*bottom_left = *bottom_right;
			*bottom_right = *top_right;
			*top_right = temp;
		}
	}
}

int main() {

	char matrix[16] = {
		'1', '2', '3', '4',
		'5', '6', '7', '8',
		'9', '0', 'a', 'b',
		'c', 'd', 'e', 'f',
	};

	printf("Before:\n");
	print_matrix(matrix, 4);

	rotate(matrix, 4);

	printf("After:\n");
	print_matrix(matrix, 4);

	return 0;

}