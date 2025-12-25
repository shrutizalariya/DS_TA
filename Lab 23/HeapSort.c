//Write a program to implement Heap Sort using Array. 
 
#include <stdio.h> 
 
void heapify(int arr[], int len, int ind) { 
    int maxInd = ind; 
    int left = 2 * ind + 1; 
    int right = 2 * ind + 2; 
 
    if (left < len && arr[left] > arr[maxInd]) 
        maxInd = left; 
 
    if (right < len && arr[right] > arr[maxInd]) 
        maxInd = right; 
 
    if (maxInd != ind) { 
        arr[maxInd] ^= arr[ind]; 
        arr[ind] ^= arr[maxInd]; 
        arr[maxInd] ^= arr[ind]; 
 
        heapify(arr, len, maxInd); 
    } 
} 
 
void buildMaxHeap(int arr[], int size) { 
    for (int i = size / 2 - 1; i >= 0; i--) { 
        heapify(arr, size, i); 
    } 
} 
 
void heapSort(int arr[], int size) { 
 
    buildMaxHeap(arr, size); 
 
    for (int i = size - 1; i > 0; i--) { 
        arr[0] ^= arr[i]; 
        arr[i] ^= arr[0]; 
        arr[0] ^= arr[i]; 
 
        heapify(arr, i, 0); 
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
 
    heapSort(arr, n); 
 
    printf("Sorted array: "); 
 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
 
    return 0; 
}