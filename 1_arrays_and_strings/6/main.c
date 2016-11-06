//  Implement a method to perform basic string compression using the
// counts of repeated characters. For example, the string aabcccccaaa
// would become a2b1c5a3. If the "compressed" string would not become
// smaller than the original string, your method should return the original
// string. You can assume the string has only uppercase and 
// lowercase letters (a - z).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *compress(char *s) {
	char compressed[strlen(s)];
	memset(compressed, 0, sizeof(compressed));
	char *p = s;
	while(*p != '\0') {
		char this = *p;
		int count = 1;
		while(*(++p) == this) {
			count++;
		}
		sprintf(compressed + strlen(compressed), "%c%d", this, count);
	}
	if(strlen(compressed) < strlen(s)) {
		strcpy(s, compressed);
	}
}

int main() {

	// Must be char arrays and not string literals
	// String literals are immutable
	char s1[128] = "grayson";
	char s2[128] = "aabcccccaaa";

	compress(s1);
	compress(s2);

	printf("Compressed:\n");
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);

	return 0;
}