#include<stdio.h>
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
void heapify(int arr[],int pos){
  int parent;
  while(pos!=1){
    parent=pos/2;
    if(arr[pos]>arr[parent]){ 
      swap(&arr[pos],&arr[parent]);
      pos=parent;
    }
    else 
      break;
  }
}
void reheapify(int arr[],int n){
  int parent,left,rigth;
  parent=1;
  while(1){
    left=2*parent;
    rigth=left+1;
    if(arr[left]>arr[parent] && arr[rigth]>arr[parent] && left<=n && rigth<=n){
      if(arr[left]>arr[rigth])
        swap(&arr[left],&arr[parent]);
      else 
        swap(&arr[rigth],&arr[parent]);
    }
    else if(arr[left]>arr[parent] && left<=n)
      swap(&arr[left],&arr[parent]);
    else if(arr[rigth]>arr[parent] && rigth<=n)
      swap(&arr[rigth],&arr[parent]);
    else
      break;
  }
}
void heapsort(int arr[],int n){
  if(n==1)
    return;
  swap(&arr[1],&arr[n]);
  reheapify(arr,n-1);
  heapsort(arr,n-1);
}
int main(){
  int n;
  int arr[10];
  printf("Enter the number to element to be added:");
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    printf("Enter the number:");
    scanf("%d",&arr[i]);
    heapify(arr,i);
  }
  printf("The array is:\n");
  for(int i=1;i<=n;i++)
    printf("%d ",arr[i]);
  printf("\n");
  heapsort(arr,n);
  printf("The Sorted array is:\n");
  for(int i=1;i<=n;i++)
    printf("%d ",arr[i]);
  printf("\n");
  return 0;
}