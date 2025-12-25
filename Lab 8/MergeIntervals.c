// Merge Intervals Problem 
// Given a set of time intervals in any order, our task is to merge all overlapping 
// intervals into one and output the result which should have only mutually 
// exclusive intervals. 
 
// Sample Example-1: 
// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}} 
// Output: {{1, 4}, {6, 8}, {9, 10}} 
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping 
// intervals here,[1,3] and [2,4]. Therefore we will merge these two and return 
// [1,4],[6,8],[9,10] 
 
// Sample Example-2: 
// Input: Intervals = {{6,8},{1,9},{2,4},{4,7}} 
// Output: {{1, 9}} 
 
#include <stdio.h> 
 
struct Interval { 
    int start; 
    int end; 
}; 
 
void sortIntervals(struct Interval arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j].start > arr[j + 1].start) { 
                struct Interval temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 
 
void mergeIntervals(struct Interval arr[], int n) { 
    sortIntervals(arr, n); 
 
    struct Interval result[100]; 
    int index = 0; 
 
    result[0] = arr[0]; 
 
    for (int i = 1; i < n; i++) { 
        // If intervals overlap 
        if (arr[i].start <= result[index].end) { 
            // Merge them by updating the end 
            if (arr[i].end > result[index].end) { 
                result[index].end = arr[i].end; 
            } 
        } else { 
            // If no overlap, move to next position 
            index++; 
            result[index] = arr[i]; 
        } 
    } 
 
    printf("Merged Intervals:\n"); 
    for (int i = 0; i <= index; i++) { 
        printf("{%d, %d}\n", result[i].start, result[i].end); 
    } 
} 
 
int main() { 
    int n; 
    struct Interval arr[100]; 
 
    printf("Enter number of intervals: "); 
    scanf("%d", &n); 
 
    printf("Enter intervals (start end):\n"); 
    for (int i = 0; i < n; i++) { 
        scanf("%d %d", &arr[i].start, &arr[i].end); 
    } 
    mergeIntervals(arr, n); 
    return 0; 
}