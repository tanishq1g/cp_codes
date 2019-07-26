#include <stdio.h>
int binarysearch(int * a,int first,int last,int key){
	int mid;
	while(first<=last){
		mid=(first+last)/2;
		if (a[mid]==key)
			return mid;
		else if(a[mid]<key)
			first=mid+1;
		else
			last=mid-1;
	
	}
	return -1;

}

int main(){
	int a[10];
	for ( int i = 0 ;i<10;i++){
		fflush(stdin);
		scanf("%d",&a[i]);
	}
	printf("%d",binarysearch(a,0,9,8));
	
	return 0;
}