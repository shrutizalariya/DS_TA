//Write a program to implement Counting Sort using Array.   
 
#include <stdio.h> 
 
void countingSort(int A[], int B[], int n, int k) { 
    int c[100] = {0};  // Temporary count array 
 
    // Initialize c[i] to 0 for i = 1 to k 
    for (int i = 0; i <= k; i++) { 
        c[i] = 0; 
    } 
     
    // count occurrences of each value in A[] 
    for (int j = 0; j < n; j++) { 
        c[A[j]]++; 
    } 
 
    // Cumulative count in c[] 
    for (int i = 1; i <= k; i++) { 
        c[i] += c[i - 1]; 
    } 
 
    // Place elements into sorted positions in B[] 
    for (int j = n - 1; j >= 0; j--) { 
        B[c[A[j]] - 1] = A[j]; 
        c[A[j]]--; 
    } 
} 
 
int main() { 
    int A[100], B[100], n, k = 0; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    printf("Enter %d elements (positive integers):\n", n); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &A[i]); 
        if (A[i] > k) 
            k = A[i]; // Find the maximum value 
    }
    countingSort(A, B, n, k); 
    printf("Sorted array:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", B[i]); 
    } 
    return 0; 
}