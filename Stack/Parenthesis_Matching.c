#include<stdio.h>
typedef struct stack{
  int top;
  int arr[100];
}STACK;
void push(char a,STACK *S){
  S->top++;
  S->arr[S->top]=a;
}
void pop(STACK *S){
  S->top--;
}
int main(){
  STACK S;
  S.top=-1;
  char str[40];
  int i;
  printf("Enter the strings of brackets:");
  fflush(stdin);
  gets(str);
  for(i=0;str[i]!='\0';i++){
    if(str[i]=='(')
      push(str[i],&S);
    else if(str[i]==')'){
      if(S.top==-1){
        printf("Extra Closing Bracket!!\n");
        break;
      }
      else
        pop(&S);
    }
  }
  if(str[i]=='\0'){
    if(S.top==-1)
        printf("Parenthesis Match Perfectlly!\n");
    else
      printf("Extra Opening Brackets!!\n");
  }
  return 0;
}
