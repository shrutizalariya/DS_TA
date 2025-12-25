//WAP to check whether a number is prime or not. 
 
#include <stdio.h> 
 
void main() 
{ 
    int num; 
    int count = 0; 
 
    printf("Enter a Number = "); 
    scanf("%d", &num); 
 
    for (int i = 2; i < num; i++) 
    { 
        if (num % i == 0) 
        { 
            count = 1; 
            break; 
        } 
    } 
 
    if (count == 0) 
    { 
        printf("%d is Prime Number", num); 
    } 
    else 
    { 
        printf("%d is Not a Prime Number", num); 
    } 
} 
