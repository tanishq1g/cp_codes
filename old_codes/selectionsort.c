#include <stdio.h>
void selectionsort(int * a,int n){
	for(int i=0 ; i<n ; i++){
		int pos=i;
		for(int j=i;j<n;j++){
			if( a[j]< a[pos] ){
				pos=j;
			}
		}
		int temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;	
	}
}

int main(){
	int a[10];
	for ( int i = 0 ;i<10;i++){
		fflush(stdin);
		scanf("%d",&a[i]);
	}
	selectionsort(a,10);
	for ( int i = 0 ;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}