//WAP to convert number of days into year, week & days 
//[e.g. 375 days mean 1 year, 1 week and 3 days]. 

#include <stdio.h> 
void main() { 
    int days, years, weeks; 

    printf("Enter number of days: "); 
    scanf("%d", &days); 

    years = days / 365; 
    days = days % 365; 
    weeks = days / 7; 
    days = days % 7; 
    
    printf("%d year, %d weeks, %d days", years, weeks, days); 
} 


//#include <stdio.h>
//
//int main() {
//    int n, h = 0, m = 0, s = 0;
//
//    printf("Enter time in second:\n");
//    scanf("%d", &n);
//
//    h = n / 3600;
//    m = (n - (h * 3600)) / 60;
//    s = (n - ((h * 3600) + (m * 60)));
//
//    printf("Time = %d:%d:%d\n", h, m, s);
//
//    return 0;
//}

