#include <stdio.h>
void bubblesort(int * a,int n){
	for(int i=0 ; i<n ; i++){
		for(int j=0;j<n-i;j++){
			if( a[j]>=a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int main(){
	int a[10];
	for ( int i = 0 ;i<10;i++)
		scanf("%d",&a[i]);
	bubblesort(a,10);
	for ( int i = 0 ;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}