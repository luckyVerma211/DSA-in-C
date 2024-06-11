#include<stdio.h>
int main(){
  int arr[]={67,35,89,16,43,90,23,77};
  int n=sizeof(arr)/sizeof(arr[0]);
  for(int i=1;i<n;i++){
    for(int j=i;j>0;j--){
      if(arr[j]<arr[j-1]){
        int temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
      }
    }
  }
  printf("The sorted array is:\n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}