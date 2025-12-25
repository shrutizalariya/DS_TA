//WAP to print Armstrong number from 1 to 1000. 
 
#include <stdio.h> 
#include <math.h> 
 
int armstrong(int); 
int len(int); 
 
void main(){ 
    int i =1; 
    while(i<=1000){ 
        int isArmStrong = armstrong(i); 
        if(isArmStrong == 1) 
        	printf("%d is armStrong\n",i); 
        i++; 
    } 
} 
 
int len(int n){ 
    int i=0; 
    for(i=0;n!=0;i++,n/=10){} 
    return i; 
} 
 
int armstrong(int n){ 
    int dummy = n; 
    int sum = 0; 
    int length = len(n); 
    while(dummy>0){ 
        sum+= pow(dummy%10,length); 
        dummy/=10; 
    } 
    return (sum == n?1:0); 
}


//1 to 9, 153, 370,371,407 is armStrong


//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int num, temp, digit, sum, n;
//
//    for (num = 1; num <= 1000; num++) {
//        temp = num;
//        n = 0;
//        
//        // Count digits
//        while (temp != 0) {
//            n++;
//            temp /= 10;
//        }
//
//        temp = num;
//        sum = 0;
//
//        while (temp != 0) {
//            digit = temp % 10;
//            sum += (int)pow(digit, n);  // cast to int to avoid float rounding issue
//            temp /= 10;
//        }
//
//        if (sum == num)
//            printf("%d is an Armstrong number\n", num);
//    }
//
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//int armstrong(int n);
//int len(int n);
//
//int main() {
//    for (int i = 1; i <= 1000; i++) {
//        if (armstrong(i)) {
//            printf("%d is armStrong\n", i);
//        }
//    }
//    return 0;
//}
//
//int len(int n) {
//    int count = 0;
//    while (n != 0) {
//        count++;
//        n /= 10;
//    }
//    return count;
//}
//
//int armstrong(int n) {
//    int sum = 0, temp = n;
//    int length = len(n);
//    while (temp > 0) {
//        int digit = temp % 10;
//        sum += pow(digit, length);
//        temp /= 10;
//    }
//    return (sum == n);
//}



