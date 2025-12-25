//Write a program to read and display n numbers using an array. 
 
#include <stdio.h> 
 
int main() { 
    int n; 
 
    // Ask the user size of array  
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    // Declare an array of size n 
    int numbers[n]; 
 
    // Input n numbers 
    printf("Enter %d numbers:\n", n); 
    for (int i = 0; i < n; i++) { 
        printf("Element %d: ", i + 1); 
        scanf("%d", &numbers[i]); 
    } 
 
    // Display the numbers 
    printf("\nYou entered:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Element %d: %d\n", i + 1, numbers[i]); 
    } 
 
    return 0; 
} 
