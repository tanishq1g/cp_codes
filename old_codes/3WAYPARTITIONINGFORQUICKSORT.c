#include <stdio.h>
int n;
int three_way_partition(int *a, int start, int end){
	int i=start+1,j=end,k=start;
	while(i<j){
		if(a[i]<a[k]){
			int temp=a[i];
			a[i]=a[k];
			a[k]=temp;
			k++;
			i++;
				
		}
		else if(a[i]==a[k]){
			i++;
			
		}
		else{
			while(a[j]>a[k])
				j--;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			j--;		
		}

	}
	return k;
}

void quicksort( int * a , int start , int end ){
	if( start >= end );
	else{
		int j=three_way_partition(a,start,end);
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