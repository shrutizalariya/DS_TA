// Given a binary tree, determine if it is height-balanced (A height-balanced binary 
// tree is a binary tree in which the depth of the two subtrees of every node never 
// differs by more than one). 
 
#include <stdio.h> 
#include <stdlib.h> 
 
struct treenode { 
    int info; 
    struct node* lptr; 
    struct node* rptr; 
}; 
 
struct treenode* insert(struct treenode* root, int val){ 
    if( root == NULL ){ 
        root = (struct treenode*)malloc(sizeof(struct treenode)); 
        root->lptr = NULL; 
        root->rptr = NULL; 
        root->info = val; 
        return root; 
    } 
    if(root->info > val){ 
        root->lptr = insert(root->lptr, val); 
    } 
    else if(root->info < val){ 
        root->rptr = insert(root->rptr, val); 
    } 
    return root; 
} 
 
int height(struct treenode* root){ 
    if(root==NULL ) return 0; 
    int rptr = height(root->rptr); 
    int lptr = height(root->lptr); 
    if(rptr>lptr) return rptr+1; 
    return lptr + 1; 
} 
 
int heightBalanced(struct treenode* root ){ 
    if(root == NULL) return 1; 
    int lptr = height(root->lptr); 
    int rptr = height(root->rptr);
      if(abs(lptr - rptr)>1) return 0; 
    return (heightBalanced(root->lptr) && heightBalanced(root->rptr)); 
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
    struct treenode *root = NULL; 
    int opr = 0; 
    do { 
        printf("Enter element for tree1 (non-positive to end) : \n"); 
        scanf("%d",&opr); 
        if(opr > 0) 
            root = insert(root,opr); 
    } while(opr>0); 
     
    printf("\nTree :\n"); 
    inOrder(root); 
    if(heightBalanced(root)){ 
        printf("\nGiven tree is height balanced !!"); 
    } 
    else { 
        printf("\nGiven tree is not height balanced !!"); 
    } 
} 
