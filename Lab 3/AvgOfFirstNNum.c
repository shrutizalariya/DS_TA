//Write a program to calculate average of first n numbers. 
 
#include <stdio.h> 
 
int main() { 
    int n; 
    float average, sum = 0; 
 
    // Enter n 
    printf("Enter the value of n: "); 
    scanf("%d", &n); 
 
    // Check for valid input 
    if (n <= 0) { 
        printf("Please enter a positive integer.\n"); 
        return 1; 
    } 
 
    // Calculate sum of first n natural numbers 
    for (int i = 1; i <= n; i++) { 
        sum += i; 
    } 
 
    // Calculate average 
    average = sum / n; 
 
    // Display the result 
    printf("The average of the first %d natural numbers is: %.2f\n", n, average); 
 
    return 0; 
}