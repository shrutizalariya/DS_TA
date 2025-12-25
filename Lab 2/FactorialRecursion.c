#include <stdio.h>
 
int fact(); 
 
int main() {
    int n;
    printf("Enter Number:\n");
    scanf("%d", &n);

    int ans = fact(n);
    printf("%d\n", ans);

    return 0;
}

int fact(int n) {
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

