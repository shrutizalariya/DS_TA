// You have an array A of integers of size N, an array B (initially empty) and a stack S 
// (initially empty). You are allowed to do the following operations:  
// • Take the first element of array A and push it into S and remove it from A.  
// • Take the top element from stack S, append it to the end of array B and remove it 
// from S.  
// You have to tell if it possible to move all the elements of array A to array B using 
// the above operations such that finally the array B is sorted in ascending order. 
// Input Format :  
// • First line will contain T, number of testcases. Then the testcases follow.  
// • First line of each testcase contains a single integer N.  
// • Second line of each testcase contains N distinct integers : A1,A2...AN.  
// Output Format :  
// For each testcase, if it possible to move all the elements of array A to array B using 
// the above operations such that finally, the array B is sorted in ascending order, 
// print "YES" (without quotes), else print "NO" (without quotes).  
// Sample Example: 
// Input :  
// 2 
// 4 
// 1 2 4 3 
// 4 
// 1 3 4 2 
 
// Output :  
// YES 
// NO 

#include <stdio.h> 
 
int top = -1; 
void push( int arr[], int size, int val); 
int pop( int arr[]); 
int peep( int arr[], int size, int n); 
 
void push( int arr[], int size, int val){ 
    if(top == size - 1) { 
        printf("\nStack overflow!!\n"); 
        return; 
    } 
    top++; 
    arr[top] = val; 
} 
 
int pop( int arr[]){ 
    if(top == -1) { 
        printf("\nStack underflow!!\n"); 
        return -1; 
    } 
    top--; 
    return arr[top+1]; 
} 
 
int peep( int arr[], int size, int n){ 
    if(top + 1 < n) { 
        printf("\nStack underflow!!\n"); 
        return 0; 
    }   
    return arr[top - n + 1]; 
} 
 
int canSort(int arr[], int n){ 
    int b[n]; 
    int stk[n]; 
    top = -1; 
 
    int ind = 0; // index for b, tracking sorted array 
    int i = 0; 
    int last = 0;
        while(i<n){ 
            int min = i; 
            for(int j = i+1;j<n;j++){ 
                if(arr[j] < arr[min]){ 
                    min = j; 
                } 
            } 
            while(i < min){ 
                push(stk,n,arr[i]); 
                i++; 
            } 
            last = arr[min]; 
            b[ind++] = last; 
            if(top >= 0 ){ // stack is not empty 
          
                arr[i] = pop(stk); 
            } 
            else i++; 
        }     
        while(top!=-1 && last < peep(stk,n,1)){ 
            last = pop(stk); 
            b[ind++] = last; 
        } 
        return (top == -1); 
} 
 
void main(){ 
    int T; 
    int current = 1; 
 
    printf("Enter no. of testcases : \n"); 
    scanf("%d",&T); 
    while(current<=T){ 
        int n; 
 
        printf("Enter number of elements : \n"); 
        scanf("%d",&n); 
 
        int arr[n];
        int i= 0; 
        while(i<n){ 
            printf("Enter element for index - %d : \n",i); 
            scanf("%d",&arr[i]); 
            i++; 
        } 
        printf("\nFor testcase - %d: \n", current); 
        if(canSort(arr,n)){ 
            printf("Yes\n"); 
        }  
        else printf("No\n"); 
        
        current++; 
    } 
} 