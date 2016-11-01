// Given a string, write a function to check if it is a permutation of
// a palindrome. A palindrome is a word or phrase that is the same
// forwards and backwards. A permutation is a rearrangement of letters.
// The palindrome does not need to be limited to just dictionary words.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool is_palindrome_perm(char *s) {
	int letters[26];
	memset(letters, 0, sizeof(letters));

	for(int i = 0; i < strlen(s); i++) {
		if(toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z') {
			letters[toupper(s[i]) - 'A']++;
		}
	}

	int num_odds = 0;
	for(int i = 0; i < 26; i++) {
		if(letters[i] % 2 != 0) {
			num_odds++;
		}
	}

	return num_odds <= 1;
}

int main() {

	char *s1 = "grayson";
	char *s2 = "taco cat";
	char *s3 = "Taco cat";

	printf("s1: %s\n", is_palindrome_perm(s1) ? "true" : "false");
	printf("s2: %s\n", is_palindrome_perm(s2) ? "true" : "false");
	printf("s3: %s\n", is_palindrome_perm(s3) ? "true" : "false");



	return 0;
}