//WAP to print Pascal triangle. 
 
#include <stdio.h>

void printPascal(int n) {
    int row[n][n];

    for (int i = 0; i < n; i++) {
        // Print spaces for alignment
        for (int space = 0; space < n - i - 1; space++) {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                row[i][j] = 1;
            else
                row[i][j] = row[i - 1][j - 1] + row[i - 1][j];

            printf("%2d", row[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printPascal(n);
    return 0;
}


// #include <stdio.h> 
 
// void main() { 
//     int n, i, j, num, spc; 
//     printf("Enter rows: "); 
//     scanf("%d", &n); 
//     for(i = 0; i < n; i++) { 
//         for(spc = 0; spc < n - i - 1; spc++) 
//             printf("  "); 
//         num = 1; 
//         for(j = 0; j <= i; j++) { 
//             printf("%4d", num); 
//             num = num * (i - j) / (j + 1); 
//         } 
//         printf("\n"); 
//     } 
// }


// #include <stdio.h>

// void printPascal(int n) {
	
// 	int line, j;
	
//     for (line = 0; line < n; line++) {
//         for (j = 0; j <= n - line - 1; j++) {
//             printf(" ");
//         }
//         int c = 1, i;
//         for (i = 0; i <= line; i++) {
//             printf("%d ", c);
//             c = c * (line - i) / (i+1);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int n;
//     printf("Enter number of rows n:\n");
//     scanf("%d", &n);
//     printPascal(n);
//     return 0;
// }