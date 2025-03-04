#include <stdio.h> // for printf

// In C, when you pass an array to a function, it decays into a pointer to its first element.
// This means char name[] is equivalent to char *name.
// So the function actually receives a pointer to a character (char *), not a full array.
/*
    - this function is exactly the same as functionWithPointerParameter

    void myFunction(char *name) {
        printf("Hello %s\n", name);
    }
*/
void functionWithPointerParameter(char name[]) { // functionWithReferenceTypeParameter
    name[0] = 'K';
    printf("Hello: %s\n", name);
}

// When calling functionWithPrimitiveTypeParameters(5, 10), copies of 5 and 10 are created inside the function
void functionWithPrimitiveTypeParameters(int x, int y) { // function with value(primitive type) parameters
    int sum = x + y;
    printf("%d\n", sum);
}

int main() {
    /* functionWithPointerParameter("Lisa"); */
    /* 
        1. "Lisa" is a string literal, stored in a read-only memory section. 
        The function receives a pointer to the first character ('L') in "Lisa".
        Attempting to modify a string literal (name[0] = 'K') causes undefined behavior(UB)!
    */

    char modifiableName[] = "Lisa"; // Stored in stack, modifiable
    functionWithPointerParameter(modifiableName); 
    printf("%s\n", modifiableName); // Kisa
    return 0;
}
