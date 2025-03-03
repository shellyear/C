#include <stdio.h> // for stdin, printf

void takeUserInput() {
    int myNum;
    printf("Type a number: \n");
    printf("Memory address of myNum is: %p\n", &myNum);


    scanf("%d", &myNum); // &myNum is the memory address of variable myNum

    char fullName[30]; 
    fgets(fullName, sizeof(fullName), stdin); // read a line of text
}

void multipleUserInput() {
    int myNum;
    char myChar;

    printf("Type a number AND a character and press enter: \n");

    scanf("%d %c", &myNum, &myChar);

    printf("Your number is: %d\n", myNum);
    printf("Your character is: %c\n", myChar);
}

int main() {
    return 0;
}