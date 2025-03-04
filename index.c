#include <stdio.h> // <stdio.h> is a header file library that lets us work with i/0 functions, such as printf(). Header files add functionality to C programs.
#include <stdlib.h>
#include <unistd.h>  // For getpid()
#include <stdbool.h>  // Import the boolean header file 
#include <ctype.h> // isspace

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

void showcasePointers() {
    int age = 20;
    char letter = 'A';
    /* A pointer is a variable that stores the memory address of another variable as its value. */
    int *agePtr = &age; // &age is a memory address of age; *agePtr is a variable holding this address
    char *letterPtr = &letter;

    printf("%p\n", agePtr); // 0x7ffe5367e044 (some memory address)
    printf("%p\n", letterPtr); // 0x7ffe5367e144 (some memory address)

    printf("%d\n", *agePtr); // DEREFENCE - *agePtr to get the value of memory address  (to get the value of the variable the pointer points to)
    // printf("%d", *&25); address-of operator (&) can only be used on variables (like &age), not constants. 
    /*
      You cannot take the address of a constant/literal (like &43).
      The reason 43 is considered a constant (or literal) is because it is a fixed value written directly in the code
      🔹 Are All Constants Immutable?
        Not always! Some constants do have memory addresses:
     */
    const int num = 25;
    printf("%p\n", &num);  // ✅ Works, because `num` is stored in memory

    /* 🔹 Does just 25 (integer literal) Exist in Memory? */
    /*    Case: 1 - Using 25 Directly (No Address) */
    printf("%d", 25); /*
        Here, 25 is an integer literal. 
        It is embedded directly into the CPU instruction.
        It does not get a memory address because it's not stored in RAM.

        How does the CPU handle this?
        - The compiler might replace printf("%d", 25); 
          with machine code that directly loads 25 into a CPU register.
          ✔ No memory storage = No memory address.
    */
   /* Case: 2 -  Assigning 25 to a Variable (Has Address) */
   int someNum = 25; // Now, 25 is stored in RAM, inside someNum's memory location. 
   printf("%p\n", &someNum); // &num gives its memory address.
   
}

void showcaseArrayAndPointers() {
    int myNumbers[4] = {25, 50, 75, 100};
    for (int i = 0; i < 4; i++) {
        printf("%p\n", &myNumbers[i]);
    }
    /*in C the name of an array, is actually a pointer to the first element of the array. */
    // When used in an expression, myNumbers is implicitly(automatically) converted to &myNumbers[0].
    printf("Memory address of array is the memory address of the first element of array: %p %p\n", myNumbers, &myNumbers[0]); 

    // Get the value of the first element in myNumbers
    printf("%d\n", *myNumbers); // 25

    /* get values from memory adresses of an array */
    printf("Get values from memory adresses of an array\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\n", *(myNumbers + i));
    }

    /* It is also possible to change the value of array elements with pointers: */
    printf("It is also possible to change the value of array elements with pointers: \n");
    *myNumbers = 13; // Change the value of the first element of the array to 13
    *(myNumbers + 1) = 17; // Change the value of the second element to 17

    printf("%d\n", *myNumbers); // 13
    printf("%d\n", *(myNumbers + 1)); // 17
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
    
    return 0;
}