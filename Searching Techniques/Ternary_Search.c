#include<stdio.h>
int Ternary_search(int arr[],int n,int X){
  int beg=0;
  int end=n-1;
  while (beg<=end){
    int mid1=beg+(end-beg)/3;
    int mid2=end-(end-beg)/3;
    if(arr[mid1]==X)
      return mid1;
    if(arr[mid2]==X)
      return mid2;
    if(X<arr[mid1])
      end=mid1-1;
    else if(X>arr[mid2]) 
      beg=mid2+1;
    else{
      beg=mid1+1;
      end=mid2-1;
    }
  }
  return -1;
}
int main(){
  //Array must be sorted
  int arr[]={11,25,39,44,51,62,78,99};
  int n=sizeof(arr)/sizeof(arr[0]);
  int X=39;
  int val=Ternary_search(arr,n,X);
  if(val==-1)
    printf("Number not found int the array!!\n");
  else
    printf("Number found in the array!!\n");
  return 0;
}