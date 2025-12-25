// In an array of 20 elements, arrange 15 different values, which are generated 
// randomly between 1,00,000 to 9,99,999. Use hash function to generate key and 
// linear probing to avoid collision. H(x) = (x mod 18) + 2. Write a program to input 
// and display the final values of array. 
 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
#define SIZE 20 
 
int main() { 
    int array[15]; 
    int hashTable[SIZE]; 
    int i, x; 
 
    for(i = 0; i < SIZE; i++) { 
        hashTable[i] = 0; 
    } 
 
    srand(time(0)); 
    for(i = 0; i < 15; i++) { 
        array[i] = (rand() % 900000) + 100000; 
    } 
 
    printf("Question Array:\n"); 
    for(i = 0; i < 15; i++) { 
        printf("%d ", array[i]); 
    } 
 
     printf("\n\nIndexes Array:\n"); 
    for(i = 0; i < 15; i++) { 
        x = (array[i] % 18) + 2; 
        printf("%d ", x); 
 
        while(hashTable[x] != 0) { 
            x = (x + 1) % SIZE; 
        } 
        hashTable[x] = array[i]; 
    } 
 
 
    printf("\n\nHash Table:\n"); 
    for(i = 0; i < SIZE; i++) { 
        printf("%d ", hashTable[i]); 
    } 
 
    return 0; 
}
