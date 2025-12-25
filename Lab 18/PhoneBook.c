// Write a program to implement phone book dictionary using Binary Search Tree 
// which provides following operations:  
// • Add new entry in phone book,  
// • Remove entry from phone book,  
// • Search phone number  
// • List all entries in ascending order of name and  
// • List all entries in descending order of name 
 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_NAME 100 
#define MAX_PHONE 20 
 
typedef struct Node { 
    char name[MAX_NAME]; 
    char phone[MAX_PHONE]; 
    struct Node* lptr; 
    struct Node* rptr; 
} Node; 
 
Node* newNode(const char* name, const char* phone) { 
    Node* node = (Node*)malloc(sizeof(Node)); 
    strncpy(node->name, name, MAX_NAME); 
    strncpy(node->phone, phone, MAX_PHONE); 
    node->lptr = node->rptr = NULL; 
    return node; 
} 
 
Node* insert(Node* root, const char* name, const char* phone) { 
    if (root == NULL) 
        return newNode(name, phone); 
    int cmp = strcmp(name, root->name); 
    if (cmp < 0) 
        root->lptr = insert(root->lptr, name, phone); 
    else if (cmp > 0) 
        root->rptr = insert(root->rptr, name, phone); 
    else 
        printf("Entry with name \"%s\" already exists.\n", name); 
    return root; 
} 
 
Node* findMinNode(Node* root) { 
    while (root && root->lptr != NULL) 
        root = root->lptr; 
    return root; 
}
Node* search(Node* root, const char* name) { 
    if (root == NULL) 
        return NULL; 
    int cmp = strcmp(name, root->name); 
    if (cmp == 0) 
        return root; 
    else if (cmp < 0) 
        return search(root->lptr, name); 
    else 
        return search(root->rptr, name); 
} 
 
Node* deleteNode(Node* root, const char* name) { 
    if (root == NULL) { 
        printf("Entry \"%s\" not found.\n", name); 
        return NULL; 
    } 
 
    int cmp = strcmp(name, root->name); 
    if (cmp < 0) { 
        root->lptr = deleteNode(root->lptr, name); 
    } else if (cmp > 0) { 
        root->rptr = deleteNode(root->rptr, name); 
    } else { 
        if (root->lptr == NULL) { 
            Node* save = root->rptr; 
            free(root); 
            printf("Deleted entry \"%s\".\n", name); 
            return save; 
        } else if (root->rptr == NULL) { 
            Node* save = root->lptr; 
            free(root); 
            printf("Deleted entry \"%s\".\n", name); 
            return save; 
        } else { 
            Node* save = findMinNode(root->rptr); 
            strcpy(root->name, save->name); 
            strcpy(root->phone, save->phone); 
            root->rptr = deleteNode(root->rptr, save->name); 
        } 
    } 
    return root; 
}
void inorder(Node* root) { 
    if (root == NULL) return; 
    inorder(root->lptr); 
    printf("%s : %s\n", root->name, root->phone); 
    inorder(root->rptr); 
} 
 
void reverseInorder(Node* root) { 
    if (root == NULL) return; 
    reverseInorder(root->rptr); 
    printf("%s : %s\n", root->name, root->phone); 
    reverseInorder(root->lptr); 
} 
 
int main() { 
    Node* phoneBook = NULL; 
    int choice; 
    char name[MAX_NAME], phone[MAX_PHONE]; 
    Node* result; 
 
    while (1) { 
        printf("\nPhone Book Menu:\n"); 
        printf("1. Add new entry\n"); 
        printf("2. Remove entry\n"); 
        printf("3. Search phone number\n"); 
        printf("4. List entries ascending\n"); 
        printf("5. List entries descending\n"); 
        printf("6. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
        getchar(); // Clear newline left by scanf
          switch (choice) { 
            case 1: 
                printf("Enter name: "); 
                gets(name);   
                printf("Enter phone number: "); 
                gets(phone); 
                phoneBook = insert(phoneBook, name, phone); 
                break; 
 
            case 2: 
                printf("Enter name to remove: "); 
                gets(name);   
                phoneBook = deleteNode(phoneBook, name); 
                break; 
 
            case 3: 
                printf("Enter name to search: "); 
                gets(name);   
                result = search(phoneBook, name); 
                if (result) 
                    printf("Phone number of %s is %s\n", name, result->phone); 
                else 
                    printf("Entry not found.\n"); 
                break; 
 
            case 4: 
                printf("Phone book entries (Ascending order):\n"); 
                inorder(phoneBook); 
                break; 
 
            case 5: 
                printf("Phone book entries (Descending order):\n"); 
                reverseInorder(phoneBook); 
                break; 
 
            case 6: 
                printf("Exiting...\n"); 
                exit(0); 
 
            default: 
                printf("Invalid choice. Try again.\n"); 
        } 
    } 
 
    return 0; 
}