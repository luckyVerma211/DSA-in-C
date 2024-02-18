#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}Node;
Node *top;
void push(int value){
  if(top==NULL){
    top=(Node*)malloc(sizeof(Node));
    top->data=value;
    top->next=NULL;
    printf("Push operation performed successfully!!\n");
  }
  else{
    Node *ptr;
    ptr=(Node*)malloc(sizeof(Node));
    ptr->next=top;
    ptr->data=value;
    top=ptr;
    printf("Push operation performed successfully!!\n");
  }
}
void pop(){
  if(top==NULL){
    printf("Underflow!!\n");
  }
  else{
    Node *ptr;
    ptr=top;
    top=top->next;
    free(ptr);
    printf("Pop operation performed successfully!!\n");
  }
}
void display(){
  printf("The Stack is:\n");
  Node *ptr;
  ptr=top;
  while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
}
int main(){
  top= NULL;
  int ans=0;
  while(ans<=3){
    int ch;
    printf("\n");
    printf("Press 1 - To Push in the Stack\n");
    printf("Press 2 - To Pop from the Stack\n");
    printf("Press 3 - To Display the Stack\n");
    printf("Press 4 - To Exit\n");
    printf("Enter the choice:");
    scanf("%d",&ch);
    if(ch==1){
      int val;
      printf("Enter the value to be pushed:");
      scanf("%d",&val);
      push(val);
    }
    else if(ch==2)
      pop();
    else if(ch==3)
      display();
    else
      break;
  }
  return 0;
}