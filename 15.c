 //15th question
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink,*rlink;
};

struct node* createnode(int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL){
        printf("\nMemory allocation failed");
        exit(0);
    }
    n->data = val;
    n->llink = NULL;
    n->rlink = NULL;
    return n;
}
struct node* insert(struct node* root,int val)
{
    struct node* n = createnode(val);
    if(root == NULL){
        return n;
    }struct node* curr = root;
    struct node* prev = NULL;
    while(curr != NULL){
        prev = curr;
        if(curr->data > n->data)
            curr = curr->llink;
        else
            curr = curr->rlink;
    }
    if(prev->data > val)
        prev->llink = n;
    else
        prev->rlink = n;
    return root;
}

void preorder(struct node* root){
    if(root == NULL)
        return;
    printf("%d  ",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}
void inorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->llink);
    printf("%d  ",root->data);
    inorder(root->rlink);
}
void postorder(struct node* root){
    if(root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d  ",root->data);
}
struct node* Delete(struct node *root,int item){
    struct node *parent=NULL,*q,*suc;
    struct node* curr = root;
    if(root == NULL){
        printf("\nEmpty tree..");
        return NULL;
    }
    while(curr != NULL && curr->data!= item){
        parent = curr;
        if(curr->data > item)
            curr = curr->llink;
        else
            curr = curr->rlink;
    }
    if( curr == NULL){
        printf("\nKey not found");
        return root;
    }
    if(curr->llink == NULL)
        q= curr->rlink;
    if(curr->rlink == NULL)
        q= curr->llink;
    else
    {
        q = suc = curr->rlink;
        while(suc->llink != NULL)
            suc = suc->llink;
        suc->llink = curr->llink;
    }
    if(parent == NULL){
        free(curr);
        return q;
    }
    if(parent->llink == curr)
        parent->llink = q;
    else
        parent->rlink = q;
    free(curr);
    return root;
}

void main()
{
    int val,choice;
    struct node *root;
    root = NULL;
    printf("\nEnter \n1.To insert \n2.To delete \n3.Display preorder \n4.Display inorder \n5.Display postorder \n6.Exit");
    do{
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("\nEnter the value to insert");
            scanf("%d",&val);
            root = insert(root,val);
            break;
            case 2 : printf("\nEnter the key to delete");
            scanf("%d",&val);
            root = Delete(root,val);
            break;
            case 3 : printf("\n");preorder(root);
            break;
            case 4 : printf("\n");inorder(root);
            break;
            case 5 : printf("\n");postorder(root);
            break;
            case 6 : exit(0);
            default : printf("\nInvalid input..");

        }
    }while(1);
}