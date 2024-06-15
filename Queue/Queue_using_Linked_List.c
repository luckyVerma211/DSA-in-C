#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}Queue;
Queue *front,*rear;
void Enqueue(int value){
  Queue *temp;
  temp=(Queue*)malloc(sizeof(Queue));
  temp->data=value;
  temp->next=NULL;
  if(front==NULL && rear==NULL){
    front=rear=temp;
  }
  else{
    Queue *ptr;
    ptr=front;
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr->next=temp;
    rear=temp;
  }
}
void Dequeue(){
  Queue *ptr;
  ptr=front;
  front=ptr->next;
  free(ptr);
}
void display(){
  Queue *ptr;
  ptr=front;
  if(ptr==NULL)
    printf("Queue is Empty!!\n");
  else{
    printf("The Queue is:\n");
    while(ptr!=NULL){
      printf("%d ",ptr->data);
      ptr=ptr->next;
    }
    printf("\n");
  }
}
int main(){
  Queue *front=NULL;
  Queue *rear=NULL;
  do{
    printf("Press 1 - To Enqueue in the Queue\n");
    printf("Press 2 - To Dequeue in the Queue\n");
    printf("Press 3 - To Display the Queue\n");
    printf("Press 4 - To Exit\n");
    int ch,val;
    printf("Enter the choice:");
    scanf("%d",&ch);
    if(ch==1){
      printf("Enter the value to be enetered:");
      scanf("%d",&val);
      Enqueue(val);
    }
    else if(ch==2)
      Dequeue();
    else if(ch==3)
      display();
    else
      break;
  }while(1);
  return 0;
}
