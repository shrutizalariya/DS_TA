//Write a program to merge two unsorted arrays. 
 
#include <stdio.h> 
 
void main() { 
    int n, m, i; 
    printf("Enter a length of first array:\n"); 
    scanf("%d", &n); 
    printf("Enter a length of second array:\n"); 
    scanf("%d", &m); 
 
    int arr[n]; 
    int arr1[m]; 
    int arr2[n + m]; 
 
 printf("\nEnter elements of first array!\n"); 
    for (i = 0; i < n; i++) { 
        printf("arr[%d] = \n", i); 
        scanf("%d", &arr[i]); 
    } 
 
 printf("\nEnter elements of second array!\n"); 
    for (i = 0; i < m; i++) { 
        printf("arr1[%d] = \n", i); 
        scanf("%d", &arr1[i]); 
    } 
 
    for (i = 0; i < n; i++) { 
        arr2[i] = arr[i]; 
    } 
 
    for (i = 0; i < m; i++) { 
        arr2[n + i] = arr1[i]; 
    } 
 
    printf("\nMerged Array!\n"); 
    for (i = 0; i < n + m; i++) { 
        printf("%d ", arr2[i]); 
    } 
 
 
}