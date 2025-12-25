//Insert a number at a given location in an array. 
 
#include <stdio.h> 
 
int main() { 
    int arr[100], n, pos, num; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    printf("Enter elements:\n"); 
    for(int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    printf("Enter position to insert: "); 
    scanf("%d", &pos); 
    printf("Enter number to insert: "); 
    scanf("%d", &num);  
 
    for(int i = n; i >= pos; i--) 
        arr[i] = arr[i - 1]; 
 
    arr[pos - 1] = num; 
    n++; 
 
    printf("Array after insertion:\n"); 
    for(int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
 
    return 0; 
}