#include <stdio.h>
int glo;
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
void selection(int *a,int start,int end,int k){
	//printf("start=%d, end=%d glo=%d\n",start,end,glo);
	if(start>end);
	else{
		int j=partition(a,start,end);
		//printf("%d\n",j);
		if(j<k){
			start=j+1;
			selection(a,start,end,k);
		}
		else if(j>k){
			end=j-1;
			selection(a,start,end,k);
		}
		else{
			glo=j;
		}
    	//for(int p =0 ;p<n;p++){
    	//	printf("%d ",a[p]);
    	//}
    	//printf("\n");
		
	}
    
}

int main(){
	
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter the __ largest element you want to find ");
	int k;
	scanf("%d",&k);
	selection(a,0,n-1,k);
	printf("%d\n",a[glo]);
	for(int p=0;p<n;p++){
		printf("%d ",a[p]);
	}printf("\n");
	return 0;
}