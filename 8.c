//8th question circular linked list
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
void insertAtPos(struct list* flist,int val,int pos){
    if(flist->head == NULL)
        createlist(flist);
    if(pos<0 || pos>flist->head->data){
        printf("\nInvalid position");
        return;
    }
    struct node* n = createnode(val);

    if(pos == 0){
        if(flist->head->link == NULL){
            n->link = n;
        }
        else{
            n->link = flist->head->link;
            struct node* tail = flist->head->link;
            while(tail->link != flist->head->link)
                tail = tail->link;
            tail->link = n;
        }
        flist->head->link = n;
        flist->head->data++;
        return;
    }
    struct node* curr = flist->head->link;
    for(int i=1;i<pos;i++)
        curr = curr->link;
    n->link = curr->link;
    curr->link = n;
        flist->head->data++;
}
void deleteAtRear(struct list* flist){
    if(flist->head == NULL || flist->head->link == NULL){
        printf("\nEmpty list");
        return;
    }
    struct node* curr = flist->head->link;
    struct node* prev = flist->head;
    while(curr->link != flist->head->link){
        prev = curr;
        curr = curr->link;
    }
    if(prev == flist->head){
        prev->link == NULL;
    }
    else{
        prev->link = curr->link;
    }
    free(curr);
    flist->head->data--;
}

void deleteAtFront(struct list* flist){
    if(flist->head == NULL || flist->head->link == NULL){
        printf("\nEmpty list");
        return;
    }
    struct node* curr = flist->head->link;
    struct node* tail = flist->head->link;
    while(tail->link != curr)
        tail = tail->link;
    if(curr == tail){
        flist->head->link = NULL;
    }
    else{
        flist->head->link = curr->link;
        tail->link = curr->link;
    }
    free(curr);
    flist->head->data--;
}
void searchByKey(struct list* flist,int key){
    if(flist->head == NULL || flist->head->link== NULL){
        printf("\nEmpty list");
        return;
    }
    struct node* curr = flist->head->link;
    int pos = 0;
    do{
        if(curr->data == key){
            printf("\nKey found at pos %d",pos);
            return;
        }
        pos++;
        curr = curr->link;
    }while(curr != flist->head->link);
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
        printf("\nEnter \n1.To insert by pos\n2.To delete at rear \n3.To delete at front \n4.to search by key \n5.To exit");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("\nEnter the data and pos ");
            scanf("%d %d",&val,&pos);
            insertAtPos(mlist,val,pos);
            display(mlist);
            break;
            case 2 : deleteAtRear(mlist);
            display(mlist);
            break;
            case 3 : deleteAtFront(mlist);
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