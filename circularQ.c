#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int max;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int max){
    q->max=max;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->max*sizeof(int));
}

void enqueue(struct Queue *q,int x){
   // if(q->front==0){
  //  q->front=-1;
   // }
    if((q->rear+1)%q->max==q->front){
        printf(" QUEUE OVERFLOW...\n");
    }
    else{
    if(q->front==-1)
     q->front=0;
   q->rear=(q->rear+1)%q->max;
    q->Q[q->rear]=x;
    }

  }

int dequeue(struct Queue *q){
   
    if(q->front==-1&&q->rear==-1)
    {
    printf("Queue underflow...\n");
        //q->front++;
    }
       
     int data=q->Q[q->front];
     if(q->front==q->rear){
        q->front=-1;
       // q->rear=-1;
     }
       
     q->front=(q->front+1)%q->max;
    
    return data;
}



void display(struct Queue *q){
   printf("\nThe Queue elements are:");
   if(q->front==-1&&q->rear==-1){
   printf("q is empty");
   }
   
    int temp=q->front;
    while(temp!=q->rear){
        // printf("The Queue is  ");
        printf(" %d",q->Q[temp]);
        printf("\t");
        temp=(temp+1)%q->max;
    } printf("%d",q->Q[temp]);
    
   
   
}

int main(){
    struct Queue q;
    create(&q,5);
    int choice,val,data;
    do{
    printf("\nenter ur choice..\n1.To enqueue\n2.To dequeue ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
       // for(int i=0;i<5;i++){
        printf("\nEnter the  value to insert at rear  ");
        scanf("%d",&val);
        enqueue(&q,val);
        display(&q);
        break;

        case 2:
        data=dequeue(&q);
         printf("\ndeleted item=%d\n",data);
        display(&q);
        break;

         case 3:
          display(&q);
        break;

        default:
        printf("invalid choice....");
        exit(0);
       

    }
    }while(choice<4);

    
        return 0;
    
}