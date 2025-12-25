// Read n numbers in an array then read two different numbers, replace 1st number 
// with 2nd number in an array and print its index and final array. 
 
#include <stdio.h> 
 
int main() { 
    int n, num1, num2; 
 
    //Enter the size of the array 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    int arr[n]; 
 
    //Enter elements 
    printf("Enter %d numbers:\n", n); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    //Read the two numbers 
    printf("Enter the number to be replaced (num1): "); 
    scanf("%d", &num1); 
    printf("Enter the new number (num2): "); 
    scanf("%d", &num2); 
 
    //Replace num1 with num2 and record indices 
    int found = 0; 
    printf("Replaced at indices: "); 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == num1) { 
            arr[i] = num2; 
            printf("%d ", i); 
            found = 1; 
        } 
    } 
 
    if (!found) { 
        printf("None (no occurrence of %d found)", num1); 
    } 
 
    //Print final array 
    printf("\nFinal array:\n"); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
 
    return 0; 
}