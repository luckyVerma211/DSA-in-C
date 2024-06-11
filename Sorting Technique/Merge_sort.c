#include<stdio.h>
void merge(int a[],int b1,int e1,int e2){
  int b2=e1+1;
  int i,j,k;
  int c[100];
  i=b1;
  k=b1;
  j=b2;
  while(i<=e1 && j<=e2){
    if(a[i]<a[j])
      c[k++]=a[i++];
    else
      c[k++]=a[j++];
  }
  if(i<=e1){
    for(;i<=e1;i++,k++)
      c[k]=a[i];
  }
  else{
    for(;j<=e2;j++,k++)
      c[k]=a[j];
  }
  for(i=b1;i<=e2;i++)
    a[i]=c[i];
}
void mergesort(int arr[],int beg,int end){
  if(beg==end)
    return;
  int mid=(beg+end)/2;
  mergesort(arr,beg,mid);
  mergesort(arr,mid+1,end);
  merge(arr,beg,mid,end);
}
int main(){
  int arr[]={40,64,35,90,12,56,89,78};
  int n=sizeof(arr)/sizeof(arr[0]);
  int beg=0;
  int end=n-1;
  mergesort(arr,beg,end);
  printf("The array is:\n");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}