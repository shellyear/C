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
    int x = 45; // local variable (declared inside a function); Local variables are stored in the stack memory (virtual memory space of the process). 
    printf("Memory address of x: %p\n", (void*)&x); // Virtual memory address; 
    /* 1. MMU (Memory Management Unit) does not allow user-space processes direct access to physical memory; 
          Instead, the OS provides each process with a virtual memory space.
          The virtual address is translated into a physical address via page tables managed by the OS.
       2. Process Isolation - Each process gets its own isolated virtual address space.
          Even if two programs declare int x = 45;, they will have different virtual addresses.
       3. Address Randomization (ASLR - Address Space Layout Randomization)
          The OS randomizes memory addresses for security.
          Running the same program multiple times may show different addresses.
    */

    printf("Size of int %zu\n", sizeof(int)); // print size of int
    return 0;
}

int main() {
    const int myNum;
    printf("%d", myNum);
    printf("PID: %d", getpid());
    return 0;
}

