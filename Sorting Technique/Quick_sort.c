#include<stdio.h>
void swap(int *num1,int *num2){
  int temp=*num1;
  *num1=*num2;
  *num2=temp;
}
int partition(int arr[],int beg,int end){
  int pivot=arr[end];
  int i=beg-1;
  for(int j=beg;j<=end;j++){
    if(arr[j]<pivot){
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[end]);
  return i+1;
}
void quick_sort(int arr[],int beg,int end){
  if(beg<end){
    int pi=partition(arr,beg,end);
    quick_sort(arr,beg,pi-1);
    quick_sort(arr,pi+1,end);
  }
}
int main(){
  int arr[]={34,89,23,47,56,73,92,12};
  int start=0;
  int last=sizeof(arr)/sizeof(arr[0]);
  quick_sort(arr,start,last-1);
  printf("The sorted list is:\n");
  for(int i=0;i<last;i++)
    printf("%d ",arr[i]);
  return 0;
}