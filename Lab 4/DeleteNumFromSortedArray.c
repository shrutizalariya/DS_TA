//Delete a number from an array sorted in ascending order 
 
#include <stdio.h> 
 
int main() { 
    int arr[100], n, num, i, pos = -1; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    printf("Enter sorted elements:\n"); 
    for(i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    printf("Enter number to delete: "); 
    scanf("%d", &num); 
 
    for(i = 0; i < n; i++) { 
        if(arr[i] == num) { 
            pos = i; 
            break; 
        } 
    } 
 
    if(pos != -1) { 
        for(i = pos; i < n - 1; i++) 
            arr[i] = arr[i + 1]; 
        n--; 
    }else{ 
       printf("Data not found\n"); 
    } 
 
    printf("Array after deletion:\n"); 
    for(i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
 
    return 0; 
}