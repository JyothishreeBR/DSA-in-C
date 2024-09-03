//5th question doubly circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *plink,*nlink;
};
struct list{
    struct node* head;
};
struct node* createnode(int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL){
        printf("\nMemory allocation failed");
        exit(0);
    }
    n->data = val;
    n->nlink = NULL;
    n->plink = NULL;
    return n;
}
void createlist(struct list* flist){
    flist->head = createnode(0);
}
void insertByOrder(struct list* flist,int val){
    if(flist->head == NULL)
        createlist(flist);
    struct node* n = createnode(val);
    if(flist->head->nlink == NULL){
        flist->head->nlink = n;
        n->nlink = n;
        n->plink = n;
        flist->head->data++;
        return;
    }
    struct node* curr = flist->head->nlink;
    struct node* tail = curr->plink;
    if(curr->data > val){
        n->nlink = flist->head->nlink;
        flist->head->nlink = n;
        n->plink = tail;
        n->nlink->plink = n;
        tail->nlink = n;
        flist->head->data++;
        return;
    }
    while(curr->nlink != flist->head->nlink && curr->nlink->data < val)
        curr = curr->nlink;
    n->nlink = curr->nlink;
    curr->nlink = n;
    n->plink = curr;
    n->nlink->plink = n;
    flist->head->data++;
}

void deleteByPos(struct list* flist,int pos){
    if(flist->head == NULL || flist->head->nlink==NULL){
        printf("\nEmpty list");
        return;
    }
    if(pos<0 || pos>=flist->head->data){
        printf("\nInvalid pos");
        return;
    }
    struct node* curr = flist->head->nlink;
    struct node* tail = curr->plink;
    if(pos == 0){
        if(curr->nlink == flist->head->nlink){
            flist->head->nlink = NULL;
        }
        else{
            flist->head->nlink = curr->nlink;
            tail->nlink = curr->nlink;
            curr->nlink->plink = tail;
        }
        free(curr);
        flist->head->data--;
    }
    else{
        for(int i=1;i<pos;i++)
            curr = curr->nlink;
        tail = curr->nlink;
        curr->nlink = tail->nlink;
        tail->nlink->plink = curr;
        free(tail);
        flist->head->data--;
    }
}
void deleteByKey(struct list* flist,int key){
    if(flist->head->nlink == NULL || flist->head == NULL){
        printf("\nEmpty list");
        return;
    }
    struct node* curr = flist->head->nlink;
    if(curr->data == key){
        deleteByPos(flist,0);
        return;
    }
    while(curr->nlink->data!=key && curr->nlink!=flist->head->nlink)
        curr = curr->nlink;
    if(curr->nlink->data == key){
        struct node* tail = curr->nlink;
        curr->nlink = tail->nlink;
        tail->nlink->plink = curr;
        flist->head->data--;
        free(tail);
        return;
    }
    printf("\nKey not found");
}
void searchByPos(struct list* flist,int pos){
    if(pos<0 || pos>=flist->head->data){
        printf("\nInvalid position");
        return;
    }
    if(pos == 0)
        printf("\nElement found at position %d is %d",pos,flist->head->nlink->data);
    else{
        struct node* curr = flist->head->nlink;
        for(int i=0;i<pos;i++)
            curr = curr->nlink;
        printf("\nElement found at position %d is %d",pos,curr->data);
    }
}
void display(struct list* flist){
    if(flist->head->nlink == NULL || flist->head==NULL){
        printf("\nEmpty list");
        return;
    }
    printf("\n");
    struct node* curr = flist->head->nlink;
    do{
        printf("%d\t",curr->data);
        curr = curr->nlink;
    }while(curr!=flist->head->nlink);
}

void main()
{
    struct list *mlist;
    mlist = (struct list*)malloc(sizeof(struct list));
    createlist(mlist);
    int choice,key,pos,val;
    do{
        printf("\nEnter \n1.To insert by order\n2.To delete by pos \n3.To delete by key \n4.to search by pos \n5.To exit");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("\nEnter the data ");
            scanf("%d",&val);
            insertByOrder(mlist,val);
            display(mlist);
            break;
            case 2 : printf("\nEnter the pos ");
            scanf("%d",&pos);
            deleteByPos(mlist,pos);
            display(mlist);
            break;
            case 3 : printf("\nEnter the key ");
            scanf("%d",&key);
            deleteByKey(mlist,key);
            display(mlist);
            break;
            case 4: printf("\nEnter the pos ");
            scanf("%d",&pos);
            searchByPos(mlist,pos);
            break;
            case 5 : exit(0);
            default:printf("\nInvalid input");
        }
    }while(1);
}