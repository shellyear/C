#include <stdio.h> // for I/O, e.g printf
#include <string.h> // imports "strlen", "strcat", "strcpy", "strcmp" and more string functions

void stringComparison() {
    char str1[] = "Hello";
    char str2[] = "Hello";

    printf("%d", strcmp(str1, str2)); // output: 0; 0 indicates that there is no difference
    printf("%d", strcmp("A", "C")); // -1; 
    printf("%d", strcmp("C", "A")); // 1;
    /*
        The return value of strcmp() is not guaranteed to be exactly -1, 0, or 1.
        It only guarantees:
            0 if the strings are equal.
            A negative value if the first string is smaller.
            A positive value if the first string is greater.
        The exact negative or positive value depends on the system/compiler implementation.
    */
}
