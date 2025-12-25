// Given an array nums with n objects colored red, white, or blue, sort them in place 
// so that objects of the same color are adjacent, with the colors in the order red, 
// white, and blue. We will use the integers 0, 1, and 2 to represent the color red, 
// white, and blue, respectively.  
// Sample Example-1: Input: nums = [2,0,2,1,1,0] Output: [0,0,1,1,2,2]  
// Sample Example-2: Input: nums = [2,0,1] Output: [0,1,2] 
 
// ----------------Using Bubble Sort------------------- 
 
#include <stdio.h> 
 
void sortColorsusingBubblesort(int nums[], int n) { 
    int temp; 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (nums[j] > nums[j + 1]) { 
                // Swap nums[j] and nums[j+1] 
                temp = nums[j]; 
                nums[j] = nums[j + 1]; 
                nums[j + 1] = temp; 
            } 
        } 
    } 
} 
 
int main() { 
    int n; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    int nums[n]; 
    printf("Enter %d elements (0 for red, 1 for white, 2 for blue):\n", n); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &nums[i]); 
 
    sortColorsusingBubblesort(nums, n); 
 
    printf("Sorted colors array:\n"); 
    for (int i = 0; i < n; i++) 
        printf("%d ", nums[i]); 
    printf("\n"); 
 
    return 0; 
} 
// ----------------Using Insertion Sort------------------- 
 
// #include <stdio.h> 
 
// void insertionSort(int nums[], int n) { 
//     for (int i = 1; i < n; i++) { 
//         int key = nums[i]; 
//         int j = i - 1; 
 
//         // Move elements greater than key to one position ahead 
//         while (j >= 0 && nums[j] > key) { 
//             nums[j + 1] = nums[j]; 
//             j--; 
//         } 
//         nums[j + 1] = key; 
//     } 
// } 
 
// int main() { 
//     int nums[100], n; 
 
//     printf("Enter number of elements (only 0, 1, or 2): "); 
//     scanf("%d", &n); 
 
//     printf("Enter %d elements (0 = red, 1 = white, 2 = blue):\n", n); 
//     for (int i = 0; i < n; i++) 
//         scanf("%d", &nums[i]); 
 
//     insertionSort(nums, n); 
 
//     printf("Sorted array (Insertion Sort):\n"); 
//     for (int i = 0; i < n; i++) 
//         printf("%d ", nums[i]); 
 
//     return 0; 
// }