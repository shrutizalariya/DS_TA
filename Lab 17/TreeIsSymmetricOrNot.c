//Write a program to check whether the given tree is symmetric or not. 
 
#include <stdio.h> 
#include <stdlib.h> 
 
struct treenode { 
    int info; 
    struct treenode* lptr; 
    struct treenode* rptr; 
}; 
 
struct treenode* newNode(int data) { 
    struct treenode* node = (struct treenode*)malloc(sizeof(struct treenode)); 
    node->info = data; 
    node->lptr = node->rptr = NULL; 
    return node; 
} 
 
int sameTree(struct treenode* root1,struct treenode* root2){ 
    if(root1==NULL && root2 == NULL) return 1; 
    if(root1 == NULL || root2 ==NULL) return 0; 
    if(root1->info != root2->info) return 0; 
    return (sameTree(root1->lptr, root2->rptr) && sameTree(root1->rptr, root2->lptr)); 
} 
 
int symmetric(struct treenode* root){ 
    if(root==NULL) return 1; 
    if(root->lptr == NULL && root->rptr ==NULL) return 1; 
    if(root->lptr == NULL || root->rptr ==NULL) return 0; 
    return sameTree(root->lptr,root->rptr); 
} 
 
void inOrder(struct treenode* root){ 
    if(root ==NULL) return; 
    printf("["); 
    inOrder(root->lptr); 
    printf(" %d ",root->info); 
    inOrder(root->rptr); 
    printf("]"); 
} 
void main(){ 
    // static treenodes. 
    struct treenode *root1 = newNode(8); 
    root1->lptr = newNode(5); 
    root1->lptr->lptr = newNode(3); 
    root1->lptr->rptr = newNode(6); 
    root1->rptr = newNode(5); 
    root1->rptr->lptr = newNode(6); 
    root1->rptr->rptr = newNode(3); 
 
    struct treenode *root2 = newNode(8); 
    root2->lptr = newNode(5); 
    root2->lptr->lptr = newNode(3); 
    root2->lptr->rptr = newNode(6); 
    root2->rptr = newNode(7); 
    root2->rptr->lptr = newNode(6); 
    root2->rptr->rptr = newNode(3); 
     
    printf("Tree 1 :\n"); 
    inOrder(root1); 
 
    if(symmetric(root1)){ 
        printf("\nGiven tree is symmetric !!\n"); 
    } 
    else { 
        printf("\nGiven tree is not symmetric!\n"); 
    } 
 
    printf("Tree 2 :\n"); 
    inOrder(root2); 
     
    if(symmetric(root2)){ 
        printf("\nGiven tree is symmetric !!"); 
    } 
    else { 
        printf("\nGiven tree is not symmetric!"); 
    } 
}

/*Extra 
 // for symmetric tree, when you want to take input from user, set elements in 
balanced manner  
 int minHeight(struct treenode* root){ 
    if(root==NULL ) return 0; 
    int rptr = minHeight(root->rptr); 
    int lptr = minHeight(root->lptr); 
    if(rptr<lptr) return rptr+1; 
    return lptr + 1; 
} 
 
struct treenode* insert(struct treenode* root, int val){ 
    if( root == NULL ){ 
        root = (struct treenode*)malloc(sizeof(struct treenode)); 
        root->lptr = NULL; 
        root->rptr = NULL; 
        root->info = val; 
        return root; 
    } 
    if(root->lptr ==NULL) root->lptr = insert(root->lptr, val); 
    else if(root->rptr ==NULL) root->rptr = insert(root->rptr, val); 
    else { 
    int lptr = minHeight(root->lptr); 
    int rptr = minHeight(root->rptr); 
    if(rptr < lptr){ 
        root->rptr = insert(root->rptr, val); 
    } 
    else { 
        root->lptr = insert(root->lptr, val); 
    } 
    } 
    return root; 
} 
*/ 