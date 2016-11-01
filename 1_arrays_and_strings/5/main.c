// There are three types of edits that can be performed on strings:
// insert a character, remove a character, or replace a character.
// Given two strings, write a function to check if they are one edit
// (or zero edits) away.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_one_away(char *s1, char *s2) {
	// See if replacing one character will fix it
	if(strlen(s1) == strlen(s2)) {
		int diff = 0;
		for(int i = 0; i < strlen(s1); i++) {
			if(s1[i] != s2[i]) {
				diff++;
			}
		}
		if(diff <= 1) {
			return true;
		}
	}
	// Removing one character from s1 will fix it
	if(strlen(s1) == strlen(s2) + 1) {
		// Allow for one conflict
		bool conflict = false;
		for(int i = 0; i < strlen(s1); i++) {
			if(conflict) {
				if(s1[i] != s2[i-1]) {
					return false;
				}
			} else {
				if(s1[i] != s2[i]) {
					conflict = true;
				}
			}
		}
	}
	// Removing one character from s2 will fix it
	if(strlen(s2) == strlen(s1) + 1) {
		// Allow for one conflict
		bool conflict = false;
		for(int i = 0; i < strlen(s2); i++) {
			if(conflict) {
				if(s2[i] != s1[i-1]) {
					return false;
				}
			} else {
				if(s2[i] != s1[i]) {
					conflict = true;
				}
			}
		}
	}
}

int main() {

	char *s1 = "grayson";
	char *s2 = "riddhi";
	char *s3 = "grayyson";
	char *s4 = "greyson";
	char *s5 = "gryson";

	printf("Compare s1 and ___:\n");
	printf("s1: %s\n", is_one_away(s1, s1) ? "true" : "false");
	printf("s2: %s\n", is_one_away(s1, s2) ? "true" : "false");
	printf("s3: %s\n", is_one_away(s1, s3) ? "true" : "false");
	printf("s4: %s\n", is_one_away(s1, s4) ? "true" : "false");
	printf("s5: %s\n", is_one_away(s1, s5) ? "true" : "false");

	return 0;
}