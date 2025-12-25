//Write a program to implement Radix Sort using Array. 
 
#include <stdio.h> 
#include <math.h> 
 
void radix(int arr[], int size, int place) { 
    int newArr[size]; 
    int count[10] = {0}; 
 
    for (int i = 0; i < size; i++) { 
        count[(arr[i] / place) % 10]++; 
    } 
 
    for (int i = 1; i < 10; i++) { 
        count[i] += count[i - 1]; //prefix sum  
    } 
 
    for (int i = size - 1; i >= 0; i--) { 
        int digit = (arr[i] / place) % 10; 
        newArr[count[digit] - 1] = arr[i]; 
        count[digit]--; 
    } 
 
    for (int i = 0; i < size; i++) { 
        arr[i] = newArr[i]; 
    } 
} 
 
void radixSort(int arr[], int size) { 
    int max = arr[0]; 
     
    for (int i = 1; i < size; i++) { 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
 
    for (int place = 1; max / place > 0; place *= 10) { 
        radix(arr, size, place); 
    } 
} 
int main() { 
    int n; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        printf("Enter element at index %d: ", i); 
        scanf("%d", &arr[i]); 
    } 
 
    radixSort(arr, n); 
 
    printf("Sorted array: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
 
    return 0; 
} 