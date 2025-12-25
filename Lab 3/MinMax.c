// Write a program to find position of the smallest number & the largest number 
// from given n numbers. 
 
#include <stdio.h> 
 
int main() { 
    int n; 
 
    //Enter size of array 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    // Validate input 
    if (n <= 0) { 
        printf("Please enter a positive number of elements.\n"); 
        return 1; 
    } 
 
    int numbers[n]; 
    int min, max, minPos = 0, maxPos = 0; 
 
    // Input the numbers 
    printf("Enter %d numbers:\n", n); 
    for (int i = 0; i < n; i++) { 
        printf("Element %d: ", i + 1); 
        scanf("%d", &numbers[i]); 
 
        if (i == 0) { 
            min = max = numbers[i];  
        } else { 
            if (numbers[i] < min) { 
                min = numbers[i]; 
                minPos = i; 
            } 
            if (numbers[i] > max) { 
                max = numbers[i]; 
                maxPos = i; 
            } 
        } 
    } 
 
    printf("Smallest number is %d at position %d\n", min, minPos + 1); 
    printf("Largest number is %d at position %d\n", max, maxPos + 1); 
 
    return 0; 
}