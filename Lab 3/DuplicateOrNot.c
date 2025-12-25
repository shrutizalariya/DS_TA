//Write a program to find whether the array contains a duplicate number or not. 
 
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter a length of array:\n");
    scanf("%d", &n);

    int arr[n]; 
    int flag = 0;
    int b = 0;

    for (i = 0; i < n; i++) {
        printf("arr[%d] = \n", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n-1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                b = arr[i];
                flag = 1;
            }
        }
    }

    if (flag == 1) {
        printf("This array contains a duplicate num and which is %d\n", b);
    } else {
        printf("This array not contains a duplicate num\n");
    }

    return 0;
}
