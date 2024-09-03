//12a.c circular que
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct queue{
    int front,rear;
    int qu[max];
};

void enqueue(struct queue* q){
    if((q->rear+1)%max == q->front){
        printf("Queue overflow..");
        return;
    }
    int val;
    printf("\nEnter the value to push : ");
    scanf("%d",&val);
    if(q->front == -1)
        q->front++;
    q->rear = (q->rear+1)%max;
    q->qu[q->rear] = val;
    printf("\nThe pushed element is %d",val);
    display(q);
}
void dequeue(struct queue* q){
    if(q->front == -1 && q->rear == -1){
        printf("\nQueue underflow..");
        return;
    }
    int item = q->qu[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front+1)%max;
    printf("\nThe poped element is %d",item);
    display(q);
}

void peek(struct queue* q){
    if(q->front == -1 && q->rear==-1){
        printf("\nEmpty stack!");
        return;
    }
    printf("\nElement at peek is %d",q->qu[q->front]);
}

void display(struct queue* q){
    if(q->front == -1 && q->rear==-1){
        printf("\nEmpty stack");
        return;
    }
    printf("\n");
    int temp = q->front;
    while(temp != q->rear){
        printf("\t%d",q->qu[temp]);
        temp = (temp+1)%max;
    }printf("\t%d",q->qu[temp]);
}
void main(){
    struct queue q;
    q.front=q.rear=-1;
    int choice;
    do{
        printf("\n1.To push 2.To pop 3.To peek 4.To exit");
        scanf("%d",&choice);
        switch(choice){
            case 1 : enqueue(&q);
            printf("\nrear is %d front is %d",q.rear,q.front);
            break;
            case 2 : dequeue(&q);
            printf("\nrear is %d front is %d",q.rear,q.front);
            break;
            case 3 : peek(&q);
            break;
            case 4 : exit(0);
            default : printf("\nInvalid input ");
        }
    }while(1);
}