#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

struct stack{
char *stack;
int maxsize;
int top;
};


struct stack* createst( int maxsize){
struct stack*s=(struct stack*)malloc(sizeof(struct stack));
 s->top = -1;
 s->maxsize=maxsize;
 s->stack=(char*)malloc(s->maxsize*sizeof(char));
 return s;
 }

void push(struct stack* s,char item) {
    if (s->top == s->maxsize-1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
  s->stack[++(s->top)] = item;
}

char pop(struct stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[(s->top)--];
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else
        return 0; // Assuming all other characters have lower precedence
}

void infixToprefix(char infix[]) {
    struct stack* s = createst(strlen(infix));
    char prefix[MAX_SIZE];
    char postfix[MAX_SIZE];
    int i, j=0;
   // char symbol;//

     // symbol=infix[i];
    for(int i=0;infix[i]!='\0';i++) {
       if (infix[i]== '(')
       infix[i]=')';
      else if (infix[i]== ')')
       infix[i]='(';

    }
     
    for(int i=0;infix[i]!='\0';i++) {

        if (isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if (infix[i]== '(')
            push(s,infix[i]);
        else if (infix[i] == ')')
         {
            while (s->stack[s->top] != '(')
                postfix[j++] = pop(s);
            pop(s); // Pop '('
        }
         else if (isOperator(infix[i])) 
         {
            while (s->top!=-1&&precedence(s->stack[s->top])>precedence(infix[i]))
                postfix[j++] = pop(s);
            push(s,infix[i]);
        }
    }

    while (s->top != -1)
        postfix[j++] = pop(s);

    postfix[j] = '\0';
    printf(" Nearly Postfix Expression: %s\n", postfix);
  
    int index=0; int len=strlen(postfix);
    while(postfix[index]!='\0'){
        prefix[len-index-1]=postfix[index];
        index++;
    }prefix[index]='\0';
  
    printf("Prefix Expression: %s\n",prefix);
   
     
}

// Function to reverse a string
void reverse_string(char a[]) {
    int length = strlen(a);
    char *str=a;
    for (int i = 0; i < length / 2; i++) {
        char temp = *(str+i);
       *(str+i)  = *(str+length-i-1);
      *( str+length-i-1) = temp;
    }
}



int evalpostfix(char postfix[]){
    struct stack *s=createst(strlen(postfix));
   // int stack[MAX_SIZE];
   
    int x1,x2,r;
    for(int i=0;postfix[i]!='\0';i++){
        if(isalnum(postfix[i]))
        push(s,postfix[i]-'0');
        else{
     x2=pop(s);x1=pop(s);
     switch(postfix[i]){
        case '+':r=x1+x2;
        push(s,r);
        break;

        case '-': r=x1-x2;
        push(s,r);
        break;

        case '*': r=x1*x2; push(s,r);
        break;

        case '/':
        r=x1/x2; push(s,r);
        break;

        default:
        printf("invalid"); break;


     
     } 
    }
    
}
r=pop(s); 
printf("the result is %d ",r);
}

void evalpre(char prefix[]){
    struct stack *s=createst(strlen(prefix));

    int r,x1,x2;
    int len=strlen(prefix);
    for(int i=len-1;i>=0;i--){
        if(isalnum(prefix[i]))
        push(s,prefix[i]-'0');

        else{
           x1=pop(s);x2=pop(s) ;
           switch(prefix[i]){
            case '+': r=x1+x2;
                   push(s,r);
                   break;
            case '-':r=x1-x2; 
                    push(s,r);
                   break;
            case '*':r=x1*x2;
             push(s,r);
                   break;

            case '/':r=x1/x2; push(s,r);
                   break;
             default:
             printf("invalid "); break;
                    
                  
           }
        }
    }
    r=pop(s);
    printf(" result is %d",r);
}






int main() {
    char infix[MAX_SIZE];
     char postfix[MAX_SIZE];
     char prefix[MAX_SIZE];
    int ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
     printf("Enter prefix expression: ");
    scanf("%s", prefix);
    reverse_string(infix);

    

   
   
  do{
     printf("\n enter 1.to covert infix to postfix and prefix\n 2.to eval post\n 3 .to eval prefix "); 
     scanf("%d",&ch);
   switch(ch){
   case 1: infixToprefix(infix); break;
   case 2: evalpostfix(postfix); break;
   case 3:evalpre(prefix);break;
   default : printf("invalid"); break;
   }
  }while(ch<4);
    
    return 0;
}