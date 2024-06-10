#include<stdio.h>
#define MAX 100
void push(int data[],int *top,int val){
  if(*top==MAX-1)
    printf("Overflow!!\n");
  else{
    (*top)++;
    data[*top]=val;
  }
}
int pop(int data[],int *top){
  if(*top==-1)
    printf("Underflow!!\n");
  else{
    int val=data[*top];
    (*top)--;
    return val;
  }
}
int main(){
  char infix[30],postfix[30];
  int i,j=0;
  int data[MAX],top=-1;
  printf("Enter the infix Expression:");
  scanf("%s",infix);
  for(i=0;infix[i]!='\0';i++){
    if(infix[i]=='(')
      push(data,&top,infix[i]);
    else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/'){
      if(top==-1 || data[top]=='(')
        push(data,&top,infix[i]);
      else if(infix[i]=='*' || infix[i]=='/'){
        if(data[top]=='*' || data[top]=='/'){
          postfix[j++]=pop(data,&top);
        }
        push(data,&top,infix[i]);
      }
      else if(infix[i]=='+' || infix[i]=='-'){
        while(top!=-1 && data[top]!='(')
          postfix[j++]=pop(data,&top);
        push(data,&top,infix[i]);
      }
    }
    else if(infix[i]==')'){
      while(data[top]!='(')
        postfix[j++]=pop(data,&top);
      pop(data,&top);
    }
    else
      postfix[j++]=infix[i];
  }
  while(top!=-1)
    postfix[j++]=pop(data,&top);
  postfix[j]='\0';
  printf("\nThe Postfix expression is: %s",postfix);
  return 0;
}