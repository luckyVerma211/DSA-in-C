#include<stdio.h>
int main(){
  int arr[]={67,35,89,16,43,90,23,77};
  int n=sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(arr[i]>arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
  printf("The sorted array is:\n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
