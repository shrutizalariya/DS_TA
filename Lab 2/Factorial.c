//WAP to find factorial of a number. 
 
#include<stdio.h> 
 
void main(){ 
    int number; 
    int ans = 1; 
     
    printf("Enter Number = "); 
    scanf("%d",&number); 
     
    for(int i = number;i>=1;i--){ 
        ans = ans*i; 
    } 
     
    printf("Factorial of %d is = %d",number,ans); 
}

