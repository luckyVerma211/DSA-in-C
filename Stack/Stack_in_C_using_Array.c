#include<stdio.h>
#include<stdlib.h>
#define Max_size 100
int stack[Max_size];
int top=-1;
void push(int value){ 
  if(top==Max_size-1){
    printf("Overflow!!\n");
    return;
  }
  stack[++top]=value;
  printf("Element added successfully!!\n");
}
void pop(){
  if(top==-1)
    printf("Underflow!!\n");
  stack[top--];
  printf("Element poped successfully!!\n");
}
void display(){
  if(top==-1)
    printf("Stack is Empty!!\n");
  else{
    printf("The stack is:\n");
    for(int i=top;i>=0;i--)
      printf("%d ",stack[i]);
    printf("\n");
  }
}
int main(){
  do{
    printf("Press 1 - To Push\n");
    printf("Press 2 - To Pop\n");
    printf("Press 3 - To Display\n");
    printf("Press 4 - To Exit\n");
    int ch,val;
    printf("Enter the choice:");
    scanf("%d",&ch);
    if(ch==1){
      printf("Enter the value:");
      scanf("%d",&val);
      push(val);
    }
    else if(ch==2)
      pop();
    else if(ch==3)
      display();
    else
      break;
  }while(1);
  return 0;
}