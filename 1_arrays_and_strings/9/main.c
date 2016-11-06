// Assume you have a method is_substring which
// checks if one word is a substring of another.
// Given two strings, s1 and s2, write code to check
// if s2 is a rotation of s1 using only one call to
// is_substring.
// (e.g., "waterbottle" is a rotation of "erbottlewat")

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_substring(char *whole, char *part) {

    return strstr(whole, part) != NULL;

}

bool is_rotation(char *s1, char *s2) {
    if(strlen(s1) != strlen(s2)) {
        return false;
    }
    char twice[strlen(s1) * 2 + 1];
    strcpy(twice, s1);
    strcpy(twice+strlen(s1), s1);
    return is_substring(twice, s2);
}

int main() {

    char *s1 = "waterbottle";
    char *s2 = "erbottlewat";
    char *s3 = "grayson";

    printf("s1 and s2: %s\n", is_rotation(s1, s2) ? "true" : "false");
    printf("s1 and s3: %s\n", is_rotation(s1, s3) ? "true" : "false");

}