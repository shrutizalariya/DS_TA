//WAP to print prime numbers between given interval.

#include <stdio.h>

int main() {
    int start, end, i, j, flag;

    printf("Enter the start of range: ");
    scanf("%d", &start);

    printf("Enter the end of range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    for (i = start; i <= end; i++) {
        if (i < 2)
            continue; // Skip numbers less than 2

        flag = 1; // Assume i is prime

        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        if (flag)
            printf("%d ", i);
    }

    return 0;
}


//#include <stdio.h> 
//#include <math.h> 
// 
//int prime(int n){ 
//    if(n<2) return 0; 
//    int i = 2; 
//    int root = (int)(pow(n,0.5)); 
//    while(i <= root){ 
//        if(n%i == 0){ 
//            return 0; 
//        } 
//        i++; 
//    } 
//    return 1; 
//} 
// 
//void primeRange(int low, int high){ 
//    if(low > high){ 
//        int temp = low; 
//        low = high; 
//        high = temp; 
//    } 
//    int count = 0; 
//    while(low<=high){ 
//        int isPrime = prime(low); 
//        if(isPrime == 1){ 
//            printf("%d, ",low); 
//            count++; 
//        } 
//        low++; 
//    } 
// 
//    if(count == 0){ 
//        printf("\nNo prime number found!"); 
//    } 
//    else printf("\b\b "); 
//} 
// 
//void main(){ 
//    int high, low; 
//    printf("Enter lowerBound and upperbound (space seperated):\n"); 
//    scanf("%d %d",&low,&high); 
//    primeRange(low,high); 
//}









//#include <stdio.h>
//#include <math.h>
//
//int prime(int n) {
//    if(n < 2) return 0;
//    int root = (int)sqrt(n);
//    for(int i = 2; i <= root; i++) {
//        if(n % i == 0) return 0;
//    }
//    return 1;
//}
//
//void primeRange(int low, int high) {
//    if(low > high) {
//        int temp = low;
//        low = high;
//        high = temp;
//    }
//
//    int found = 0;
//    for(int i = low; i <= high; i++) {
//        if(prime(i)) {
//            if(found) printf(", ");
//            printf("%d", i);
//            found = 1;
//        }
//    }
//
//    if(!found)
//        printf("No prime number found!");
//}
//
//int main() {
//    int low, high;
//    printf("Enter lowerBound and upperBound (space separated):\n");
//    scanf("%d %d", &low, &high);
//    primeRange(low, high);
//    return 0;
//}

