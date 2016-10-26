// Grayson Pike, 2016
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Using no additional data structures
// very slow for large strings, exponential runtime
bool is_unique(char *s) {
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(s[i] == s[j] && i != j) {
                return false;
            }
        }
    }
    return true;
}

// using an array, assuming that ascii goes from 0-127
// linear runtime
bool is_unique2(char *s) {
    int len = strlen(s);
    bool used[128];
    memset(used, 0, sizeof(used));

    for(int i = 0; i < len; i++) {
        if(used[(int) s[i]]) {
            return false;
        } else {
            used[(int) s[i]] = true;
        }
    }
    return true;
}

int main() {

    char *s1 = "grayson";
    char *s2 = "riddhi";

    printf("Using is_unique:\n");
    printf("s1 unique: %s\n", is_unique(s1) ? "true" : "false");
    printf("s2 unique: %s\n", is_unique(s2) ? "true" : "false");

    printf("Using is_unique2:\n");
    printf("s1 unique: %s\n", is_unique2(s1) ? "true" : "false");
    printf("s2 unique: %s\n", is_unique2(s2) ? "true" : "false");

    return 0;
}