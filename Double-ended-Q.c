#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void insertRare(struct Queue *q,int x){
    if(q->rear==q->size-1){
        printf(" QUEUE OVERFLOW...\n");
    }
    else{
    if(q->front==-1)
    q->front=0;
    q->rear++;
    q->Q[q->rear]=x;
    }

  }
   void insertFront(struct Queue*q,int x){
    if(q->front==-1&&q->rear==-1){
     q->front=0;
    q->rear++;
    q->Q[q->rear]=x;
     printf("value inserted at front successfully");
    

    }
   
  else if(q->front>0){
    q->front--;
    q->Q[q->front]=x; 
    printf("value inserted at front successfully");

  }
else
 printf("value inserted at front not possible");

}

void deleteFront(struct Queue *q){
  //  if(q->front==q->rear)
       if(q->front==-1&&q->rear==-1||q->front>q->rear)
   
   printf("Queue underflow...\n");
    else{
       // q->front++;
        printf("\ndeleted item at front=%d\n",q->Q[q->front]);
         q->front++;
    }
    
}

void deleteRare(struct Queue*q)
{
    if(q->rear==-1||q->front>q->rear){
    printf("Queue underflow...\n");
    }
    printf("deleted item at rear=%d\n",q->Q[q->rear]);
    q->rear--;
}

 void display(struct Queue *q){
     printf("\nThe Queue elements are:");
     
    for(int i=q->front;i<=q->rear;i++){
        // printf("The Queue is  ");2
        printf(" %d",q->Q[i]);
        printf("\t");
    }
     printf("\n");
     }

    

   int main(){
    struct Queue q;
    create(&q,5);
    int choice,val;
    do{
    printf("\nenter ur choice..\n1.To enqueue at rare\n2.To enqueue at front\n 3.delete at front\n 4.delete at rare");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("\nEnter the value to insert at rear  ");
        scanf("%d",&val);
        insertRare(&q,val);
        display(&q);
        break;

        case 2:
         printf("\nEnter the value to insert at front  ");
        scanf("%d",&val);
        insertFront(&q,val);
        display(&q);
        break;

        case 3:
        deleteFront(&q);
        display(&q);
        break;

        case 4:deleteRare(&q);
        display(&q);
        break;


        default:
        printf("invalid choice....");
        exit(0);
       

    }
    }while(choice<5);

   } 

