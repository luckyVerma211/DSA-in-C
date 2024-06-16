#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *left,*right;
}BSTree;
BSTree *root;
void addNode(int value){
  BSTree *ptr, *temp;
  temp=(BSTree*)malloc(sizeof(BSTree));
  temp->data=value;
  temp->left=NULL;
  temp->right=NULL;
  if(root==NULL)
    root=temp;
  else{
    ptr=root;
    while(ptr!=NULL){
      if(value>ptr->data){
        if(ptr->right==NULL){
          ptr->right=temp;
          break;
        }
        else
          ptr=ptr->right;
      }
      else if(value<ptr->data){
        if(ptr->left==NULL){
          ptr->left=temp;
          break;
        }
        else
          ptr=ptr->left;
      }
      else{
        printf("Duplicate elements are not allowed!!\n");
        free(temp);
        break;
      }
    }
  }
}
void preorder(BSTree *ptr){
  if(ptr==NULL)
    return;
  printf("%d ",ptr->data);
  preorder(ptr->left);
  preorder(ptr->right);
}
void inorder(BSTree *ptr){
  if(ptr==NULL)
    return;
  inorder(ptr->left);
  printf("%d ",ptr->data);
  inorder(ptr->right);
}
void postorder(BSTree *ptr){
  if(ptr==NULL)
    return;
  postorder(ptr->left);
  postorder(ptr->right);
  printf("%d ",ptr->data);
}
int main(){
  root=NULL;
  int ch,num;
  do{
    printf("Press 1 - To Add a Node\n");
    printf("Press 2 - To Travese the Tree in Preorder\n");
    printf("Press 3 - To Travese the Tree in Inorder\n");
    printf("Press 4 - To Travese the Tree in Postorder\n");
    printf("Press 5 - To Exit\n");
    printf("Enter the choice:");
    scanf("%d",&ch);
    if(ch==1){
      printf("Enter the number to be added:");
      scanf("%d",&num);
      addNode(num);
    }
    else if(ch==2){
      printf("The Preorder traversal is:\n");
      preorder(root);
      printf("\n");
    }
    else if(ch==3){
      printf("The Inorder traversal is:\n");
      inorder(root);
      printf("\n");
    }
    else if(ch==4){
      printf("The Postorder traversal is:\n");
      postorder(root);
      printf("\n");
    }
    else 
      break;
  }while(1);
  return 0;
}
