// Write a method to replace all spaces in a string with '%20.
// You may assume that the string has sufficient space at the
// end to hold the additional characters, and that you are given
// the "true" length of the string.

#include <stdio.h>
#include <string.h>

// Assumes sufficient space in char array to hold %20's
void urlify(char *s) {
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] == ' ') {
			// shift all chars down 2
			for(int j = strlen(s) + 1; j > i + 1; j--) {
				s[j] = s[j-2];
			}
			// replace space with %20
			s[i] = '%';
			s[i+1] = '2';
			s[i+2] = '0';
		}
	}
}

int main() {

	char s[256];
	strcpy(s, "this is a sentence");

	printf("Original: %s\n", s);
	urlify(s);
	printf("URLified: %s\n", s);

}