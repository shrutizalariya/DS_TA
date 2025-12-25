// Write a menu driven program to implement Binary Search Tree (BST) & perform 
// following operations:  
// • Insert a node  
// • Delete a node  
// • Search a node  
// • Preorder Traversal  
// • Postorder Traversal  
// • Inorder Traversal  
 
#include <stdio.h> 
#include <stdlib.h> 
 
struct treenode { 
    int info; 
    struct treenode* lptr; 
    struct treenode* rptr; 
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
int search(struct treenode* root, int val){ 
    if( root == NULL ){ 
        return 0; 
    } 
 
    if(root->info > val){ 
        return search(root->lptr, val); 
    } 
 
    if(root->info < val) { 
        return search(root->rptr, val); 
    } 
    return 1; 
} 
 
struct treenode* delete(struct treenode* root,int val){ 
    if( root == NULL ){ // check the null 
        return root; 
    } 
    //find the node with given value 
    if(root->info > val){  
        root->lptr = delete(root->lptr, val); 
    } 
 
    else if(root->info < val) { 
        root->rptr = delete(root->rptr, val); 
    } 
    // if any of side is null, we can return otherside 
    else if(root->lptr == NULL){ 
        struct treenode* save = root->rptr; 
        free(root); 
        return save; 
    } 
 
    else if(root->rptr == NULL){ 
        struct treenode* save = root->lptr; 
        free(root); 
        return save; 
    }
    // Combine sides and return top element of it 
    else { 
        // go rptrmost of lptr side 
        struct treenode* lptr = root->lptr; 
        while(lptr->rptr !=NULL) 
            lptr = lptr->rptr; 
 
        // join rptr side to lptr's rptrmost   
        lptr->rptr = root->rptr; 
        lptr = root->lptr; 
        free(root); 
 
        return lptr; 
    } 
 
    return root; 
} 

// struct treenode* deleteNode(struct treenode* root, int value) {
//     if (root == NULL)
//         return root;
//     if (value < root->info)
//         root->left = deleteNode(root->left, value);
//     else if (value > root->info)
//         root->right = deleteNode(root->right, value);
//     else {
//         if (root->left == NULL) {
//             struct treenode* temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL) {
//             struct treenode* temp = root->left;
//             free(root);
//             return temp;
//         }
//         struct treenode* temp = minValueNode(root->right);
//         root->info = temp->info;
//         root->right = deleteNode(root->right, temp->info);
//     }
//     return root;
// }
 
void postOrder(struct treenode* root){ 
    if(root ==NULL) return; 
 
    printf(" %d ",root->info); 
    postOrder(root->lptr); 
    postOrder(root->rptr); 
} 
 
void inOrder(struct treenode* root){ 
    if(root ==NULL) return; 
     
    inOrder(root->lptr); 
    printf(" %d ",root->info); 
    inOrder(root->rptr); 
 
} 
 
void preOrder(struct treenode* root){ 
    if(root ==NULL) return; 
 
    preOrder(root->lptr); 
    preOrder(root->rptr); 
    printf(" %d ",root->info); 
}
void main(){ 
    struct treenode *root = NULL; 
    int opr = 0; 
    int val; 
    while(1) { 
        printf("Select operation to perform on binary search tree : \n"); 
        printf("1) ADD GIVEN NUMBER\n"); 
        printf("2) DELETE GIVEN NUMBER\n"); 
        printf("3) SEARCH GIVEN NUMBER\n"); 
        printf("4) POST-ORDER\n"); 
        printf("5) IN-ORDER\n"); 
        printf("6) PRE-ORDER\n"); 
        printf("7) TERMINATE CODE\n"); 
 
        scanf("%d",&opr); 
 
        switch (opr) 
        { 
        case 1: 
            printf("Enter number : \n"); 
            scanf("%d",&val); 
            root = insert(root,val); 
            break; 
        case 2: 
            printf("Enter number : \n"); 
            scanf("%d",&val); 
            root = delete(root,val); 
            break; 
         
        case 3:     
            printf("Enter number : \n"); 
            scanf("%d",&val); 
            if(search(root,val)){ 
                printf("\nGiven number exists in BST.\n"); 
            } 
            else { 
                printf("\nGiven number does not exist in BST.\n"); 
            } 
            break;
             case 4: 
            printf("\n"); 
            postOrder(root); 
            printf("\n"); 
            break; 
        case 5: 
            printf("\n"); 
            inOrder(root); 
            printf("\n"); 
            break; 
        case 6: 
            printf("\n"); 
            preOrder(root); 
            printf("\n"); 
            break; 
        case 7: 
            return; 
            break; 
        default: 
            break; 
        } 
    }  
}