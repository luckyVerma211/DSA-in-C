#include<stdio.h>
int Binary_search(int arr[],int n,int X){
  int beg=0;
  int end=n-1;
  while(beg<=end){
    int mid=(beg+end)/2;
    if(arr[mid]==X)
      return 1;
    else if(arr[mid]<X)
      beg++;
    else 
      end--;
  }
  return -1;
}
int main(){
  //Array must be sorted
  int arr[]={11,25,39,44,51,62,78,99};
  int n=sizeof(arr)/sizeof(arr[0]);
  int X=25;
  int val=Binary_search(arr,n,X);
  if(val==-1)
    printf("Number not found int the array!!\n");
  else
    printf("Number found in the array!!\n");
  return 0;
}