// Write a program to determine if an input character string is of the form aibi 
// where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’. 
 
#include <stdio.h> 
#include <string.h> 
 
#define SIZE 100 
 
int stack[SIZE]; 
int top = -1; 
 
void push(int value) { 
    if (top >= SIZE - 1) { 
        printf("Stack Overflow\n"); 
    } else { 
        stack[++top] = value; 
    } 
} 
 
int main() { 
    char str[SIZE]; 
    int i = 0, countB = 0; 
    int valid = 1; 
 
    printf("Enter the string (like aaabbb): "); 
    scanf("%s", str); 
 
    while (str[i] != '\0') { 
        if (str[i] == 'a') { 
            push(1); 
        } else if (str[i] == 'b') { 
            countB++; 
        } else { 
            valid = 0; 
            break; 
        } 
        i++; 
    }

    if (valid && (top + 1) == countB) { 
        printf("Valid String (a^i b^i)\n"); 
    } else { 
        printf("Invalid String\n"); 
    }
    
    return 0; 
}  