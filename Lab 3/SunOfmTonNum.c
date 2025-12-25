//Write a program to calculate sum of numbers from m to n. 
 
#include <stdio.h> 
 
int main() { 
    int m, n, sum = 0; 
 
    // Enter the range 
    printf("Enter the starting number (m): "); 
    scanf("%d", &m); 
    printf("Enter the ending number (n): "); 
    scanf("%d", &n); 
 
    // Check if m is less than or equal to n 
    if (m > n) { 
        printf("Invalid input: m should be less than or equal to n.\n"); 
        return 1; 
    } 
 
    // Calculate sum from m to n 
    for (int i = m; i <= n; i++) { 
        sum += i; 
    } 
 
    // Display the result 
    printf("Sum from %d to %d is: %d\n", m, n, sum); 
 
    return 0; 
} 
