#include <stdio.h> // <stdio.h> is a header file library that lets us work with i/0 functions, such as printf(). Header files add functionality to C programs.
#include <stdlib.h>
#include <unistd.h>  // For getpid()
#include <stdbool.h>  // Import the boolean header file 
#include <string.h> // imports "strlen", "strcat", "strcpy" and more string functions


int byteInterpetation() {
    int x = 65; // same as int x = 'A'
    char c = x;
    char cc = 65;
    printf("%c\n", c);
    printf("%d\n", x);
    // The same bytes can be interpreted differently depending on how you access them.
    // In C, character literals are treated as small integer constants.
    printf("%d\n", 'A'); // 65
    printf("%c\n", 'A'); // A 
    // 'A' is equivalent to its ASCII (or Unicode) value, which is 65 in decimal.
    int sum = 'A' + 1;  // Works naturally as 'A' is an int (value 65) (by default); So, the expression 'A' + 1 is just integer addition: 65 + 1 = 66. 
    printf("%d", sum); // 66

    /*
        - char Can Be Either Signed or Unsigned
        - In C, char is implementation-defined, meaning it can be either signed char or unsigned char, 
          depending on the compiler and system.
        - signed char - Always -128 to 127
        - unsigned char	- Always 0 to 255
    */
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
    int x = 45; // local variable (declared inside a function);
    /*
        Local variables are stored in the stack memory (virtual memory space of the process). 
        The stack is an abstraction, referring to a region in the virtual address space of a process.
        The stack appears continuous in virtual memory but is scattered in physical memory.
        The OS and CPU MMU handle mapping stack pages from virtual to physical memory.
    */ 
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
    char str[20] = "Hello ";
    char str2[] = "World";
    strcat(str, str2);
    printf("%s", str);
    return 0;
}