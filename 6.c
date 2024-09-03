//6th question circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
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
    n->link = NULL;
    return n;
}
void createlist(struct list* flist){
    flist->head = createnode(0);
}
void insertAtFront(struct list* flist,int val){
    if(flist->head == NULL)
        createlist(flist);
    struct node* n = createnode(val);
    if(flist->head->link == NULL){
        flist->head->link = n;
        n->link = n;
        flist->head->data++;
        return;
    }
    struct node* curr = flist->head->link;
    while(curr->link != flist->head->link)
        curr = curr->link;
    n->link = flist->head->link;
    flist->head->link = n;
    curr->link = n;
    flist->head->data++;
}
void insertAtRear(struct list* flist,int val){
    if(flist->head == NULL)
        createlist(flist);
    struct node* n = createnode(val);
    if(flist->head->link == NULL){
        flist->head->link = n;
        n->link = n;
        flist->head->data++;
        return;
    }
    struct node* curr = flist->head->link;
    while(curr->link != flist->head->link)
        curr = curr->link;
    n->link = curr->link;
    curr->link = n;
    flist->head->data++;
}
void deleteByKey(struct list* flist,int key){
    if(flist->head == NULL || flist->head->link== NULL){
        printf("\nEmpty list");
        return;
    }
    struct node* curr = flist->head->link;
    struct node* tail = curr;
    while(tail->link != curr)
        tail = tail->link;
    if(curr->data == key){
        if(curr->link == flist->head->link){
            flist->head->link = NULL;
        }else{
            tail->link = curr->link;
            flist->head->link = curr->link;
        }
        free(curr);
        flist->head->data--;
        return;
    }
    else{
        while(curr->link!=flist->head->link && curr->link->data!=key)
            curr = curr->link;
        if(curr->link->data == key){
            tail = curr->link;
            curr->link = tail->link;
            free(tail);
            flist->head->data--;
            return;
        }
        printf("\nKey not found");
    }
}
void searchByPos(struct list* flist,int pos){
    if(pos<0 || pos>=flist->head->data){
        printf("\nInvalid position");
        return;
    }
    if(pos == 0)
        printf("\nElement found at position %d is %d ",pos,flist->head->link->data);
    else{
        struct node* curr = flist->head->link;
        for(int i=0;i<pos;i++)
            curr = curr->link;
        printf("\nElement found at pos %d is %d",pos,curr->data);
    }
}
void display(struct list* flist){
    if(flist->head->link == NULL || flist->head==NULL){
        printf("\nEmpty list");
        return;
    }
    printf("\n");
    struct node* curr = flist->head->link;
    do{
        printf("%d\t",curr->data);
        curr = curr->link;
    }while(curr!=flist->head->link);
}

void main()
{
    struct list *mlist;
    mlist = (struct list*)malloc(sizeof(struct list));
    createlist(mlist);
    int choice,key,pos,val;
    do{
        printf("\nEnter \n1.To insert at front\n2.To insert at rear \n3.To delete by key \n4.to search by position \n5.To exit");
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