#include<stdio.h>
#include<stdlib.h>
/*void insertBypos(int* a,int *size,int pos,int val);
void deleteBypos(int* a,int *size,int pos);
int searchBykey(int* a,int *size,int key);
void display(int *a,int *size);*/

 void display(int *a,int *size){
    printf("array elelments are");
    for(int i=0;i<*size;i++)
    printf("%d\t",*(a+i));
    printf("\n");

}

void insertBypos(int *a,int *size,int pos,int val){
    if(pos>=0&&pos<*size){
       
    for(int i=(*size-1);i>=pos;i--)
    {
        *(a+i+1)=*(a+i);
    }
    *(a+pos)=val;
    (*size)++; 
    }
    else
    printf("insertion by position failed");
}

void deleteBypos(int *a,int *size,int pos){
     if(pos>=0&&pos<*size){
       
    for(int i=pos+1;i<*size;i++)
    {
        *(a+i-1)=*(a+i);
    }

    (*size)--; 
    }
    else
    printf("invalid position...");

}

int searchBykey(int *a,int *size,int key){
    for(int i=0;i<*size;i++){
        if(*(a+i)==key)
       // printf("key found at the position %d",i);
        return i;
    }
    return -1;
}

void deleteBykey(int *a,int *size,int key ){
    int pos=searchBykey(a,size,key);
    if(pos!=-1){
        deleteBypos(a,size,pos);
        
    }
    else
    printf(" invalid key.... key not found");
}

void insertBykey(int *a,int *size,int key,int val){
    int pos=searchBykey(a,size,key);
    if(pos!=-1){
        insertBypos(a,size,pos,val);
    }
    else
    printf("key not found imsertion faiied");
}

void searchBypos(int *a,int*size,int pos){
    if(pos>=0&&pos<*size)
    printf("key found at position %d is %d",pos,*(a+pos));
    else
    printf("key not found at position %d",pos);
}

void reverse(int *a,int *size){
    int len=(*size)-1;
    for(int i=0;i<len;i++){
    int temp=*(a+i);
    *(a+i)=*(a+len);
    *(a+len)=temp;
    len--;
    }
}

void sort(int *a,int *size){
    for(int i=0;i<*size;i++)
    for(int j=0;j<(*size)-1;j++){
    if(*(a+j)>*(a+j+1)){
    int temp=*(a+j);
    *(a+j)=*(a+j+1);
    *(a+j+1)=temp;
    }
    }
   // display(a,size);
}

void insertByorder(int *a,int*size,int val){
    int i;
    for( i=*(size)-1;*(a+i)>val;i--){
        *(a+i+1)=*(a+i);
    }
    *(a+i+1)=val;
    (*size)++;
    display(a,size);
}

int main(){
    int *a,pos,val,key,choice,size;
    
    printf("enter size the of the array");
    scanf("%d",&size);

     a=(int*)malloc( size * sizeof(int));
    printf("enter the %d array elements",size);
    for(int i=0;i<size;i++){
        scanf("%d",(a+i));
    }

    do{
        printf(" enter\n1.to insertBypos\n2.to deleteBypos\n3.to searchBykey\n4.to deleteBykey\n5.insertBykey\n6.searchBypos\n7.to reverse\n8.to insertByorder");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter the pos and val to insert ");
            scanf("%d%d",&pos,&val);
            insertBypos(a,&size,pos,val);
            display(a,&size);
            break;

           case 2:printf("enter the pos to delete");
            scanf("%d",&pos);
            deleteBypos(a,&size,pos);
            display(a,&size);
            break;

            case 3:
            printf("enter the key to search");
            scanf("%d",&key);
             int ele=searchBykey(a,&size,key);
            printf("key found at pos %d\n ",ele);
            display(a,&size);
            break;

            case 4: printf("enter the key to delete");
            scanf("%d",&key);
            deleteBykey(a,&size,key);
            display(a,&size);break;

            case 5:
            printf("enter the key and value to insert");
            scanf("%d%d",&key,&val);
            insertBykey(a,&size,key,val);
            display(a,&size);
            break;

            case 6:printf("enter the pos to find key");
            scanf("%d",&pos);
            searchBypos(a,&size,pos);
            display(a,&size);break;

            case 7:printf("array elements before reversing");
            display(a,&size);
            printf("after reversuing");
            reverse(a,&size);
            display(a,&size);
            break;

            case 8:
            printf("enter the value to insert at order");
            scanf("%d",&val);
            sort(a,&size);
            insertByorder(a,&size,val);break;

            default:
            printf("invalid choice...");
            break;

        }
    
   }while(choice<9);
    return 0;
}



