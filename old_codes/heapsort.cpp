#include <iostream>
using namespace std;

void sink(int *a, int n,int x){
	while(x<n){
		int j=2*x;
		if (j>=n)
			break;
		else if(j+1>=n){
			if(a[x]>=a[j])
				break;
			else{
				int temp=a[j];
				a[j]=a[x];
				a[x]=temp;
				break;
			}
				
		}
		else if(a[x]>a[j] && a[x]>a[j+1])
			break;
		else{
			int k= ( a[j]>=a[j+1] ) ? j:j+1;
			int temp=a[k];
			a[k]=a[x];
			a[x]=temp;
			x=k;
		}	
	}
}

void swim(int *a,int n , int x){
	int k=x/2;
	while(k>0){
		if(a[k]>=a[x])
			break;
		else{
			int temp=a[k];
			a[k]=a[x];
			a[x]=temp;
			x=k;
			k=k/2;

		}
	}

}

void binarytree(int *a, int n){
	for(int i=(n/2) ; i>0 ; i--){
		sink(a,n,i);
	}
}

void heapsort(int*a,int n){
	binarytree(a,n);
	n--;
	while(n>0){
		int temp=a[n];
		a[n]=a[1];
		a[1]=temp;
		sink(a,n,1);
		n--;
	}
}

int main(){
	int n,i,p;	
	cin >> n;
	int a[++n];

	for(i=1;i<n;i++)
		cin>>a[i];
	
	heapsort(a,n);
	for(p=1;p<n;p++){
		cout << a[p] <<' ';
	}
	return 0;
} 