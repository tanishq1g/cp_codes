#include <stdio.h>

int find(int *a,int *s,int n,int x){
	while(x!=a[x])
		x=a[x];
	return x;
}


int connected(int *a,int *s, int n, int p, int q){
	int pp,pq;
	pp=find(a,s,n,p);
	pq=find(a,s,n,q);
	if ( pp==pq)
		return 1;
	else
		return 0;
}

void connect(int *a,int *s,int n,int p,int q){
	if(connected(a,s,n,p,q)){
		printf("already connected");
	}
	else{
		int pp,pq;
		pp=find(a,s,n,p);
		pq=find(a,s,n,q);
		if(s[pp]>=s[pq]){
			a[pq]=pp;
			s[pp]+=s[pq];
		}
		else{
			a[pp]=pq;
			s[pq]+=s[pp];
		}

	}
}

void display(int *a,int *s,int n){
	for ( int i =0 ;i < n;i ++){
		printf("ele - %d : point to -%d , size : %d \n",i , a[i], s[i]);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int s[n];
	for(int i =0 ;i < n; i++){
		a[i]=i;
		s[i]=1;
	}
	char choice='y';
	do{
		int ch;
		printf("1)display\n2)connect\n3)connected\n4)find parent\nenter choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: display(a,s,n);
					break;
			case 2: printf("enter two elements you want to enter-\n");
					int p,q;
					scanf("%d",&p);scanf("%d",&q);
					connect(a,s,n,p,q);
					break;
			case 3:break;
			case 4:printf("enter element whose parent you want to find:\n");
					int x;
					scanf("%d",&x);
					printf("%d",find(a,s,n,x));
					break;
		}
		//printf("do you want to continue(y/n)");
		//scanf("%c",&choice);
		//scanf("%c",&choice);
	}while(choice=='y');

}