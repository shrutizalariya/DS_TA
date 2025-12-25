// Valid Parenthesis Problem 
// Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'. 
// Now Chef wants to know if the given string is balanced or not. 
// If is balanced then print 1, otherwise print 0. 
// A balanced parenthesis string is defined as follows: 
// • The empty string is balanced 
// • If P is balanced then (P), {P}, [P] is also balanced 
// • if P and Q are balanced PQ is also balanced 
// • "([])", "({})[()]" are balanced parenthesis strings 
// • "([{]})", "())" are not balanced. 
 
// Input Format: 
// The first line of the input contains a single integer T denoting the number of 
// test cases. The description of T test cases follows. The first and only line of 
// each test case contains a single string 
 
// Output Format: 
// For each test case, print a single line containing the answer. 
  
// Sample Example: 
// Output: 
// 1 
// 0 
// 1 
// 0 
 
// Input: 
// 4 
// () 
// ([)] 
// ([{}()])[{}] 
// [{{}] 
 
 
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
 
char pop() { 
    if (top == -1) {
        printf("Stack Underflow!\n"); 
        return -1;
    }
    else 
        return stack[top--];
} 
 
int isMatching(char open, char close) { 
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '[' && close == ']'); 
} 
 
int isBalanced(char str[]) { 
    top = -1; // reset stack for each test case 
    for (int i = 0; str[i] != '\0'; i++) { 
        char ch = str[i]; 
        if (ch == '(' || ch == '{' || ch == '[') { 
            push(ch); 
        } else if (ch == ')' || ch == '}' || ch == ']') { 
            char open = pop(); 
            if (!isMatching(open, ch)) { 
                return 0; 
            } 
        } 
    } 
    return top == -1;  
} 
int main() { 
    int T, i; 
    i=1; 
    int caseNum=1; 
    char str[SIZE]; 
 
    printf("Enter the number of cases: "); 
    scanf("%d", &T);  
 
    while (i<=T) { 
        printf("Case %d: ", caseNum); 
        scanf("%s", str); 
        if (isBalanced(str)) 
            printf("1\n"); 
        else 
            printf("0\n"); 
        caseNum++; 
        i++; 
    } 
 
    return 0; 
}