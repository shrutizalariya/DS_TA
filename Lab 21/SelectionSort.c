//Write a program to implement Selection Sort using Array. 
 
#include <stdio.h> 
 
void selectionSort(int arr[], int n) { 
    int i, j, minIndex, temp; 
 
    for (i = 0; i < n - 1; i++) { 
        minIndex = i; 
 
        // Find the minimum element in unsorted part 
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[minIndex]) 
                minIndex = j; 
        } 
 
        // Swap the found minimum element with first element 
        if (minIndex != i) { 
            temp = arr[i]; 
            arr[i] = arr[minIndex]; 
            arr[minIndex] = temp; 
        } 
    } 
} 
 
int main() { 
    int n, i; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    int arr[n]; 
    printf("Enter %d elements:\n", n); 
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    selectionSort(arr, n); 
 
    printf("Sorted array (Selection Sort):\n"); 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
 
    return 0; 
}