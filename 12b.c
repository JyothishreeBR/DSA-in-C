//12b. c double ended                                                                            #include<stdio.h>
#include<stdlib.h>
int max = 4;

struct queue{
    int front,rear;
    int* arr;
};

void enqueueAtRear(struct queue* q,int val){
    if(q->rear >= max-1){
            printf("\nReallocating...");
        q->arr = (int*)realloc(q->arr,2*max*(sizeof(int)));
        max = 2*max;
    }
    if(q->front == -1)
        q->front = 0;
    *(q->arr+(++q->rear)) = val;
}
void enqueueAtFront(struct queue* q,int val){
    if(q->front == -1 && q->rear == -1){
        *(q->arr+(++q->rear)) = val;
        q->front = 0;
        display(q);
        return;
    }
    if(q->front == 0){
        printf("\nReallocating...");
        q->arr = (int*)realloc(q->arr,2*max*(sizeof(int)));
        int i;
        for(i=q->rear ; i>= q->front ; i--){
                *(q->arr+i+max) = *(q->arr+i);
        }q->front = q->front+max;q->rear=q->rear+max;
        max = 2*max;
    }
        *(q->arr+(--q->front)) = val;
        display(q);
}

void dequeueAtFront(struct queue* q){
    if(q->front == -1 && q->rear == -1 || q->front > q->rear){
        printf("\nQueue overflow..");
        return;
    }
    int item = *(q->arr + q->front++);
    printf("\nThe poped element is %d",item);
}
void dequeueAtEnd(struct queue* q){
    if(q->front == -1 && q->rear == -1 || q->front > q->rear){
        printf("\nQueue overflow..");
        return;
    }
    int item = *(q->arr+q->rear--);
    printf("\npoped element is %d",item);
    display(q);
}
void peek(struct queue* q){
    if(q->front == -1 && q->rear == -1){
        printf("\nEmpty!");
        return;
    }
    printf("\nThe top element is %d",*(q->arr+q->front));
}
void display(struct queue* q){
    if(q->front == -1 && q->rear == -1){
        printf("\nEmpty!");
        return;
    }
    printf("\n");
    int temp = q->front;
    while(temp != q->rear){
        printf("%d\t",*(q->arr+temp));
        temp = (temp+1)%max;
    }
        printf("%d\t",*(q->arr+temp));
}

void main(){
    struct queue qu;
    qu.front=qu.rear=-1;
    qu.arr = (int*)malloc(max*sizeof(int));
    int choice, val;
    do{
        printf("\nEnter 1.To enqueue at rear 2.To enqueue at front 3.To dequeue at front 4.To dequeue at rear 5.To peek 6.To exit");
        scanf("%d",&choice);
        switch(choice){
                case 1 : printf("\nEnter the value to enqueue : ");
                scanf("%d",&val);
                enqueueAtRear(&qu,val);
                display(&qu);
                printf("\nRear is %d front is %d max is %d",qu.rear,qu.front,max);
                break;
                case 2 : printf("\nEnter the value to enqueue : ");
                scanf("%d",&val);
                enqueueAtFront(&qu,val);
                printf("\nRear is %d front is %d max is %d",qu.rear,qu.front,max);
                break;
                case 3 : dequeueAtFront(&qu);
                display(&qu);
                printf("\nRear is %d front is %d max is %d",qu.rear,qu.front,max);
                break;
                case 4 : dequeueAtEnd(&qu);
                printf("\nRear is %d front is %d max is %d",qu.rear,qu.front,max);
                break;
                case 5 : peek(&qu);
                break;
                case 6 : exit(0);
        }
    }while(1);
}