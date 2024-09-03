//4th question circular linked list
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

void insertByOrder(struct list* flist,int val){
    if(flist->head == NULL)
        createlist(flist);
    struct node* n = createnode(val);
    if(flist->head->link == NULL){
        flist->head->link = n;
        n->link = n;
        flist->head->data++ ;
        return;
    }
    struct node* curr=flist->head->link;
    struct node* tail = curr;
    while(tail->link != flist->head->link)
        tail = tail->link;
    if(curr->data > val){
        n->link = flist->head->link;
        flist->head->link = n;
        tail->link = n;
        flist->head->data++ ;
        return;
    }
    while(curr->link->data < val && curr->link != flist->head->link)
        curr = curr->link;
    n->link = curr->link;
    flist->head->data++ ;
    curr->link = n;
}

void deleteByPos(struct list* flist,int pos){
    if(pos<0 || pos>=flist->head->data){
        printf("\nInvalid position");
        return;
    }
    struct node* curr = flist->head->link;
    struct node* tail = curr;
    while(tail->link != curr)
        tail = tail->link;
    if(pos == 0){
        if(curr->link == curr){
            flist->head->link = NULL;
        }else{
            flist->head->link = curr->link;
            tail->link = curr->link;
        }
        free(curr);
        flist->head->data--;
    }
    else{
        for(int i=1;i<pos;i++)
            curr = curr->link;
        tail = curr->link;
        curr->link = tail->link;
        free(tail);
        flist->head->data--;
    }
}

int searchByKey(struct list* flist,int key){
    if(flist->head->link == NULL){
        printf("\nEmpty list");
        return -1;
    }
    int pos = 0;
    struct node* curr = flist->head->link;
    do{
        if(curr->data == key)
            return pos;
        pos++;
        curr = curr->link;
    }while(curr != flist->head->link);
    return -1;
}

void deleteByKey(struct list* flist,int key){
    int pos = searchByKey(flist,key);
    if(pos!= -1)
        deleteByPos(flist,pos);
    else
        printf("\nKey not found");
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
        printf("\nEnter \n1.To insert by order \n2.To delete by position \n3.To search by key \n4.to delete by key \n5.To exit");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("\nEnter the data ");
            scanf("%d",&val);
            insertByOrder(mlist,val);
            display(mlist);
            break;
            case 2 : printf("\nEnter the position ");
            scanf("%d",&pos);
            deleteByPos(mlist,pos);
            display(mlist);
            break;
            case 3 : printf("\nEnter the key ");
            scanf("%d",&pos);
            key = searchByKey(mlist,pos);
            if(key != -1)
                printf("\nKey found at position %d",key);
            else
                printf("\nKey not found");
            break;
            case 4: printf("\nEnter the key ");
            scanf("%d",&key);
            deleteByKey(mlist,key);
            display(mlist);
            break;
            case 5 : exit(0);
            default:printf("\nInvalid input");
        }
    }while(1);
}