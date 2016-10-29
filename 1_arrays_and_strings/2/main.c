// Given two strings, write a method to decide if one is a permutation of the other.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Assuming 128 characters in the ASCII set
bool is_perm(char *s1, char *s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if(len1 != len2) {
		return false;
	}

	int a1[128];
	int a2[128];
	memset(a1, 0, sizeof(a1));
	memset(a2, 0, sizeof(a2));

	for(int i = 0; i < len1; i++) {
		a1[s1[i]] ++;
	}
	for(int i = 0; i < len1; i++) {
		a2[s2[i]] ++;
	}

	for(int i = 0; i < 128; i++) {
		if(a1[i] != a2[i]) {
			return false;
		}
	}

	return true;
}

int main() {

	char *s1 = "grayson";
	char *s2 = "riddhi";
	char *s3 = "nosyarg";

	printf("Checking permutations:\n");
	printf("s1 and s2: %s\n", is_perm(s1, s2) ? "true" : "false");
	printf("s1 and s3: %s\n", is_perm(s1, s3) ? "true" : "false");

}