#include <stdio.h> // <stdio.h> is a header file library that lets us work with i/0 functions, such as printf(). Header files add functionality to C programs.
#include <stdlib.h>
#include <unistd.h>  // For getpid()

int byteInterpetation() {
    int x = 65;
    char c = x;
    printf("%c\n", c);
    printf("%d\n", x);
    // The same bytes can be interpreted differently depending on how you access them.
    return 0;
}

int demonstrate_memory_reuse() {
    int *p = malloc(4);  // Allocate memory for an int
    printf("Memory before: %d\n", *p); // Might print garbage value

    *p = 100;  // Store 100
    printf("Stored: %d\n", *p);

    free(p);  // Free memory (but data still exists)

    int *q = malloc(4);  // Reallocate memory
    printf("Memory after reallocation: %d\n", *q); // Might print 100 (old data)
    
    return 0;
}

int printMemoryAddress() {
    int x = 45;
    printf("Memory address of x: %p\n", (void*)&x); // Virtual memory address; MMU does not allow direct access to physical memory; The virtual address is translated into a physical address via page tables managed by the OS.
    printf("Size of int %zu\n", sizeof(int)); // print size of int
    return 0;
}

int main() {
    const int myNum;
    printf("%d", myNum);
    printf("PID: %d", getpid());
    return 0;
}

