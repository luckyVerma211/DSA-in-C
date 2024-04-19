#include<stdio.h>
#define MAXSIZE 100
typedef struct stack{
  int stArr[MAXSIZE];
  int top;
}STACK;
void display(STACK *S,int top){
  if(top==-1){
    printf("Stack is Empty!!\n");
  }
  else{
    printf("The Stack is:\n");
    for(int i=top;i>=0;i--){
      printf("%d ",S->stArr[i]);
    }
    printf("\n");
  }
}
void Push(STACK *S,int val){
  if(S->top==MAXSIZE-1){
    printf("OVERFLOW!!\n");
    return;
  }
  else{
    S->stArr[++S->top]=val;
    printf("Push operation performed successfully!!\n");
  }
}
void Pop(STACK *S){
  if(S->top==-1){
    printf("UNDERFLOW!!\n");
    return;
  }
  else{
    printf("The Element poped is: %d\n",S->stArr[S->top--]);
    printf("Pop operation performed successfully!!\n");
  }
}
void Peek(STACK *S){
  if(S->top==-1){
    printf("Stack is Empty!!\n");
    return;
  }
  printf("The Peek value is: %d\n",S->stArr[S->top]);
}
int isFULL(STACK *S){
  if(S->top==99)
    return 1;
  else 
    return 0;
}
int isEmpty(STACK *S){
  if(S->top==-1)
    return 1;
  else
    return 0;
}
int main(){
  STACK S;
  S.top=-1;
  do{
    printf("Press 1 - To Display the stack\n");
    printf("Press 2 - To Push into the stack\n");
    printf("Press 3 - To Pop into the stack\n");
    printf("Press 4 - To fetch the peek value\n");
    printf("Press 5 - To Check stack is full\n");
    printf("Press 6 - To Check stack is Empty\n");
    printf("Press 7 - To Exit\n");
    int ch,res;
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        display(&S,S.top);
        break;
      case 2:
        int val;
        printf("Enter the value to be pushed:");
        scanf("%d",&val);
        Push(&S,val);
        break;
      case 3:
        Pop(&S);
        break;
      case 4:
        Peek(&S);
        break;
      case 5:
        res=isFULL(&S);
        if(res==0)
          printf("Stack is not Full!!\n");
        else
          printf("Stack is Full!!\n");
        break;
      case 6:
        res=isEmpty(&S);
        if(res==0)
          printf("Stack is not Empty!!\n");
        else
          printf("Stack is Empty!!\n");
        break;
      default:
        break;
    }
    if(ch>6)
      break;
  }while(1);
  return 0;
}