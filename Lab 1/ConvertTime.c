//WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS 
//[e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)]. 
 
#include <stdio.h> 
 
void main() { 
    int seconds, h, m, s; 
    printf("Enter seconds: "); 
    scanf("%d", &seconds); 
 
    h = seconds / 3600; 
    seconds = seconds % 3600; 
    m = seconds / 60; 
    s = seconds % 60; 
 
    printf("Time : %02d:%02d:%02d", h, m, s); 
}

//#include <stdio.h>
//
//int main() {
//    int n;
//    printf("Enter days:\n");
//    scanf("%d", &n);
//
//    int y = n / 365;
//    int w = (n - (y * 365)) / 7;
//    int d = n - ((y * 365) + (w * 7));
//
//    printf("Answer = %d year %d week %d days\n", y, w, d);
//
//    return 0;
//}

//#include <stdio.h>
//
//void main() {
//    int input_days, years = 0, weeks = 0, days;
//
//    printf("Enter number of days: ");
//    scanf("%d", &input_days);
//
//    int temp = input_days;
//
//    // Count number of years
//    while (temp >= 365) {
//        years++;
//        temp -= 365;
//    }
//
//    // Count number of weeks
//    while (temp >= 7) {
//        weeks++;
//        temp -= 7;
//    }
//
//    // Remaining days
//    days = temp;
//
//    printf("%d year(s), %d week(s), %d day(s)\n", years, weeks, days);
//}

