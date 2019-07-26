#include <stdio.h>


void merge(int *a,int *b, int start, int mid , int end){
	int i,j,k;
	for(i=start,j=mid+1,k=start;i<=mid && j<=end;k++){
		if(a[i]>=a[j])
			b[k]=a[j++];
		else
			b[k]=a[i++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=end)
		b[k++]=a[j++];
	for(i=start;i<=end;i++)
		a[i]=b[i];
	
}
void mergesort(int *a,int *b,int start, int end){
	if(start>=end);
	else{
		int mid;
		mid=start+(end-start)/2;
		mergesort(a,b,start,mid);
		mergesort(a,b,mid+1,end);
		merge(a,b,start,mid,end);

	}

}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n],b[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,b,0,n-1);
	for(int p=0;p<n;p++)
		printf("%d ",arr[p]);
	return 0;
}