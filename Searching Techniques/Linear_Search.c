#include<stdio.h>
int linear_search(int arr[],int n,int X){
  for(int i=0;i<n;i++){
    if(arr[i]==X)
      return 1;
  }
  return -1;
}
int main(){
  int arr[]={45,78,90,23,18,95,40};
  int n=sizeof(arr)/sizeof(arr[0]);
  int X=100;
  int val=linear_search(arr,n,X);
  if(val==-1)
    printf("Number not found int the array!!\n");
  else
    printf("Number found in the array!!\n");
  return 0;
}
