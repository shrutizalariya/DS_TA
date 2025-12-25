#include <stdio.h> 
#include <stdlib.h> 
 
// Node structure 
struct Node { 
    int coeff; 
    int exp; 
    struct Node* link; 
}; 
 
// Function to create a polynomial 
struct Node* create() { 
    struct Node *first = NULL, *last = NULL; 
    char ans = 'y'; 
     
    while (ans == 'y' || ans == 'Y') { 
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
        printf("Enter the coefficient: "); 
        scanf("%d", &newNode->coeff); 
        printf("Enter the exponent: "); 
        scanf("%d", &newNode->exp); 
        newNode->link = NULL; 
 
        if (first == NULL) { 
            first = last = newNode; 
        } else { 
            last->link = newNode; 
            last = newNode; 
        } 
 
        printf("Do you want to add more terms? (y/n): "); 
        scanf(" %c", &ans);  // the space before %c to consume newline 
    } 
 
    return first; 
} 
// Function to add two polynomials 
struct Node* polyAdd(struct Node* poly1, struct Node* poly2) { 
    struct Node* result = NULL; 
    struct Node* last = NULL; 
 
    while (poly1 != NULL && poly2 != NULL) { 
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
        newNode->link = NULL; 
 
        if (poly1->exp == poly2->exp) { 
            newNode->coeff = poly1->coeff + poly2->coeff; 
            newNode->exp = poly1->exp; 
            poly1 = poly1->link; 
            poly2 = poly2->link; 
        } else if (poly1->exp > poly2->exp) { 
            newNode->coeff = poly1->coeff; 
            newNode->exp = poly1->exp; 
            poly1 = poly1->link; 
        } else { 
            newNode->coeff = poly2->coeff; 
            newNode->exp = poly2->exp; 
            poly2 = poly2->link; 
        } 
 
        if (result == NULL) { 
            result = last = newNode; 
        } else { 
            last->link = newNode; 
            last = newNode; 
        } 
 } 
    // Add remaining terms 
    while (poly1 != NULL) { 
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
        newNode->coeff = poly1->coeff; 
        newNode->exp = poly1->exp; 
        poly1 = poly1->link; 
    } 
    while (poly2 != NULL) { 
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
        newNode->coeff = poly2->coeff; 
        newNode->exp = poly2->exp; 
        poly2 = poly2->link; 
    } 
    return result; 
}
// Function to display a polynomial 
void display(struct Node* poly) { 
    while (poly != NULL) { 
        printf("%dx^%d", poly->coeff, poly->exp); 
        poly = poly->link; 
        if (poly != NULL) 
            printf(" + "); 
    } 
    printf("\n"); 
} 
 
int main() { 
    struct Node *poly1, *poly2, *poly3; 
 
    printf("Enter the first polynomial:\n"); 
    poly1 = create(); 
    printf("\n"); 
 
    printf("Enter the second polynomial:\n"); 
    poly2 = create(); 
    printf("\n"); 
 
    poly3 = polyAdd(poly1, poly2); 
 
    printf("The resultant polynomial is: "); 
    display(poly3); 
 
    return 0; 
} 