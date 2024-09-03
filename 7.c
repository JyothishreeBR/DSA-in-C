//7th question doubly circular linked list
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

void insertAtFront(struct list* flist,int val){
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
    struct node* tail = flist->head->nlink->plink;
    n->nlink = flist->head->nlink;
    flist->head->nlink = n;
    n->nlink->plink = n;
    n->plink = tail;
    tail->nlink = n;
    flist->head->data++;
}
void insertAtRear(struct list* flist,int val){
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
    struct node* tail = flist->head->nlink->plink;
    struct node* curr = flist->head->nlink;
    n->nlink = tail->nlink;
    tail->nlink = n;
    curr->plink = n;
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
void searchByKey(struct list* flist,int key){

    struct node* curr = flist->head->nlink;
    int pos = 0;
    do{
        if(curr->data == key){
            printf("\nKey found at pos %d",pos);
            return;
        }
        curr = curr->nlink;
        pos++;
    }while(curr!=flist->head->nlink);
    printf("\nKey not found");
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
        printf("\nEnter \n1.To insert at front\n2.To insert at rear \n3.To delete by pos \n4.to search by key \n5.To exit");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("\nEnter the data ");
            scanf("%d",&val);
            insertAtFront(mlist,val);
            display(mlist);
            break;
            case 2 : printf("\nEnter the data ");
            scanf("%d",&val);
            insertAtRear(mlist,val);
            display(mlist);
            break;
            case 3 : printf("\nEnter the pos ");
            scanf("%d",&pos);
            deleteByPos(mlist,pos);
            display(mlist);
            break;
            case 4: printf("\nEnter the key ");
            scanf("%d",&key);
            searchByKey(mlist,key);
            break;
            case 5 : exit(0);
            default:printf("\nInvalid input");
        }
    }while(1);
}