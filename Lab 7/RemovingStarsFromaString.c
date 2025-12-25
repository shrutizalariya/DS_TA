// Removing stars from a string Problem 
// You are given a string s, which contains stars *. In one operation, you can: 
// Choose a star in s. Remove the closest non-star character to its left, as well as 
// remove the star itself. Return the string after all stars have been removed. 
 
// Note : 
// • The input will be generated such that the operation is always possible. 
// • It can be shown that the resulting string will always be unique. 
 
// Sample Example-1: 
// Input: s = "leet**cod*e". 
// Output: "lecoe" 
 
// Sample Example-2: 
// Input: s = "erase*****" 
// Output: "" 
 
#include <stdio.h> 
#include <string.h> 
 
#define SIZE 1000 
 
char stack[SIZE]; 
int top = -1; 
 
void push(char ch) { 
    if (top == SIZE - 1) 
        printf("Stack Overflow!\n"); 
    else { 
        stack[++top] = ch; 
    } 
} 
 
void pop() { 
    if (top != -1) { 
        top--; 
    }else{ 
        printf("Invalid String!"); 
    } 
} 
int main() { 
    char s[SIZE]; 
    printf("Enter the string: "); 
    scanf("%s", s); 
 
    for (int i = 0; s[i] != '\0'; i++) { 
        if (s[i] == '*') { 
            pop(); 
        } else { 
            push(s[i]); 
        } 
    } 
 
    printf("Output: "); 
    for (int i = 0; i <= top; i++) { 
        printf("%c", stack[i]); 
    } 
    printf("\n"); 
 
    return 0; 
} 
