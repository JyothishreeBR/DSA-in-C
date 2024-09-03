//14th question
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* llink;
    int data;
    struct node* rlink;
};
struct node* createnode(int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("\nMemory allocation failed");
        exit(0);
    }
    n->data = val;
    n->llink = NULL;
    n->rlink = NULL;
    return n;
}
struct node* insert(struct node* root,int val){
    if(root == NULL){
        root = createnode(val);
        return root;
    }
    else if(val < root->data)
        root->llink = insert(root->llink,val);
    else
        root->rlink = insert(root->rlink,val);
    return root;
}

void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%d  ",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}
void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->llink);
    printf("%d  ",root->data);
    inorder(root->rlink);
}
void postorder(struct node* root){
    if(root == NULL){
        return;
    }
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d  ",root->data);
}

void searchByKey(struct node* root,int key)
{
    if(root == NULL){
        printf("\nEmpty tree key not found");
        return;
    }
    struct node* curr = root;
    struct node* parent = NULL;
    while(curr != NULL && curr->data!=key){
        parent = curr;
        if(key < curr->data)
            curr = curr->llink;
        else
            curr = curr->rlink;
    }
    if(curr == NULL){
        printf("\nKey not found");
        return;
    }
    if(parent == NULL){
        printf("\nKey found at root node so no parent");
    }
    else{
        printf("\nKey found and its parent is %d",parent->data);
    }
}

int counting(struct node* root){
    if(root == NULL)
        return 0;
    return 1+counting(root->llink)+counting(root->rlink);
}
int height(struct node* root){
    if(root == NULL)
        return 0;
    return 1+Max(height(root->llink),height(root->rlink));
}

int Max(int a,int b){
    return (a>b)?a:b;
}

void MaxKey(struct node* root)
{
    if(root == NULL){
        printf("\nEmpty tree!");
        return;
    }
    struct node* curr = root;
    struct node* par = NULL;
    while(curr->rlink != NULL){
        par = curr;
        curr = curr->rlink;
    }
    if(par == NULL){
        printf("\nThe max key value found at root so no parent and the value is %d",curr->data);
    }
    else
        printf("\nThe max key value found the value is %d and it's parent is %d",curr->data,par->data);
}

void main()
{
    struct node* root;
    root = NULL;
    int key,val,choice,Count;
    do{
        printf("\nEnter \n1.To insert \n2.To traversal \n3.To search \n4.To count nodes \n5.To find height \n6.To find node with max data \n7.To exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("\nEnter the data to insert");
            scanf("%d",&val);
            root = insert(root,val);
            break;
            case 2 : printf("\nEnter \n1.for preorder \n2.for inorder \n3.for postorder");
            scanf("%d",&val);
            switch(val){
                case 1 : preorder(root);
                break;
                case 3 : postorder(root);
                break;
                case 2 : inorder(root);
                break;
                default : printf("\nInvalid Input");
            }
            break;
            case 3 : printf("\nEnter the key");
            scanf("%d",&val);
            searchByKey(root,val);
            break;
            case 4 :  Count = counting(root);
            printf("\nThe total no of nodes are %d",Count);
            break;
            case 5 : Count = height(root);
            printf("\nThe height is %d",Count);
            break;
            case 6 : MaxKey(root);
            break;
            case 7 : exit(0);
            default : printf("\nInvalid Input");
        }
    }while(1);
}