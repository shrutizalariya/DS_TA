//WAP to find power of a number using loop 
 
#include <stdio.h> 
 
void main() 
{ 
    int x, power, ans = 1; 
     
    printf("Enter val of x :"); 
    scanf("%d", &x); 
     
    printf("Enter Power of x You Want :"); 
    scanf("%d", &power); 
     
    for (int i = 1; i <= power; i++) 
    { 
        ans = ans * x;         
    } 
     
    printf("The %d Power of %d is : %d", power, x, ans); 
}
