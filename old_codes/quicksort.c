#include <stdio.h>
int n;
int partition(int *a, int start, int end){
	int i=start,j=end+1;
	while( 1 ){
		while(a[++i]<=a[start] && i<=end);
		while(a[--j]>=a[start] && j>start);
		if (i>=j)
			break;
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	int temp=a[start];
	a[start]=a[j];
	a[j]=temp;
	return j;
}

void quicksort(int *a,int start,int end){
	if(start>=end);
	else{
		int j=partition(a,start,end);
		quicksort(a,start,j-1);
		quicksort(a,j+1,end);
	}
}

int main(){
	
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(int p=0;p<n;p++){
		printf("%d ",a[p]);
	}
	return 0;
}