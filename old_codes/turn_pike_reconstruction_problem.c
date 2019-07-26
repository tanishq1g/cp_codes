#include <stdio.h>
#include <stdlib.h>


struct node{
	int a;
	struct node * next;
}*head,*max;

int isempty(){
	if(head==NULL)
		return 1;
	else
		return 0;
}

int isoneelement(){
	if(head->next==NULL)
		return 1;
	else
		return 0;
}

void display(){
	printf("\n");
	if(isempty());
		//printf("empty stack\n");
	else{
		struct node * curr;
		curr=head;
		do{
			printf("%d ",curr->a);
			curr=curr->next;
		}while(curr!=NULL);
		printf("\n");
	}
}

void add(int ele){
	//printf("added element is %d\n",ele);
	struct node *ne=(struct node *)malloc(sizeof(struct node));
	ne->a=ele;
	ne->next=NULL;
	if(isempty()){
		head=ne;
		max=ne;
		//printf("%d\n",tail->a);
	}
	else{
		if(max->a<ne->a)
			max=ne;
		//printf("%d %d\n",max->a,ne->a);
		ne->next=head;
		head=ne;	
	}
}

int del(int ele){
	if(isempty())
		return 0;
	else if(isoneelement()){
		if (head -> a==ele){
	//		printf("deleted element is . %d\n",head->a);

			free(head);
			head=NULL;
			return 1;
		}
		else
			return 0;
	}
	else{
		struct node * temp2;
		struct node * temp1;
		temp1=head;
		temp2=temp1->next;
		if (temp1->a==ele){
	//		printf("deleted element is ..%d\n",temp1->a);
			head=temp1->next;
			free(temp1);
			return 1;
		}
		while(temp2!=NULL){
			if( temp2->a==ele){
	//			printf("deleted element is ..%d\n",temp2->a);
				temp1->next=temp2->next;
				free(temp2);
				return 1;
			}
			temp1=temp1->next;
			temp2=temp2->next;				
		}
	}

	return 0;
}

void findmax(){
	if(isempty());
	else if(isoneelement()){
		max=head;
	}
	else{
		max=head;
		struct node*curr=head->next;
		while(curr!=NULL){
			if(curr->a > max->a)
				max=curr;
			curr=curr->next;
		}
	}
	//printf("max is %d\n",max->a);
}

int rec(int *x,int n,int r,int l,int p,int ele){
	//printf("\n       n=%d r=%d l=%d p=%d ele=%d \n\n",n,r,l,p,ele);
	if(r<l)
		return 1;
	x[p]=ele;
	int flag;
	//del(max->a);
	if (l==p){
		flag=1;
		for(int i=0;i<l;i++){
			int k=del(ele-x[i]);
		//	printf("k-%d\n",k);
			if(k==0){
				flag=0;
			}
		//	printf("flag-%d\n",flag);
			if(flag==0){
				for(int j=0;j<i;j++)
					add(ele-x[i]);
				break;
			}
		}
		for(int i=r;i<n;i++){
			int k=del(x[i]-ele);
		//	printf("k-%d\n",k);

			if(k==0){
				flag=0;
			}
		//	printf("flag-%d\n",flag);

			if(flag==0){
				for(int j=0;j<l;j++)
					add(ele-x[j]);
				for(int j=r;j<i;j++)
					add(x[j]-ele);
				break;
			}
		}
	}
	else{
		flag=1;
		for(int i=0;i<=l;i++){
			int k=del(ele-x[i]);
		//	printf("k-%d\n",k);
			if(k==0){
				flag=0;
			}
		//	printf("flag-%d\n",flag);
			if(flag==0){
				for(int j=0;j<i;j++)
					add(ele-x[i]);
				break;
			}
		}
		for(int i=r+1;i<n;i++){
			int k=del(x[i]-ele);
		//	printf("k-%d\n",k);

			if(k==0){
				flag=0;
			}
		//	printf("flag-%d\n",flag);

			if(flag==0){
				for(int j=0;j<=l;j++)
					add(ele-x[j]);
				for(int j=r+1;j<i;j++)
					add(x[j]-ele);
				break;
			}
		}
	}
	///display();
	//for(int q=0;q<n;q++)
	//	printf("%d ",x[q]);
	//printf("\n");
	if(isempty())
		return 1;
	if(flag==1){
		findmax();
		int k=rec(x,n,r-1,l,r-1,max->a);
		if(k==0){
			findmax();
			int t=rec(x,n,r,l+1,l+1,x[n-1]-max->a);
			if(t==0){
				for(int i=0;i<=l;i++)
					add(ele-x[i]);
				for(int i=r+1;i<n;i++)
					add(x[i]-ele);
				return 0;
			}
		}
		return 1;
	}
	else
		return 0;

}
int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for (int i = 0; i < n; ++i)
		scanf("%d",&arr[i]);
	
	head=NULL;
	
	int m=n*(n-1)/2;
	printf("m=%d\n",m);	
	
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			int k=arr[i]-arr[j];			
			add(k);
		}
	}

	display();

	int x[n];
	x[0]=0;
	x[n-1]=max->a;
	del(max->a);
	display();
	findmax();
	int r=n-2,l=0;
	
	if(rec(x,n,r,l,r,max->a)==0)
		if (rec(x,n,r,l,l,x[n-1]-max->a)==0){
			printf("\nnot possible");
		
		}

	//display();
	for(int q=0;q<n;q++)
		printf("%d ",x[q]);
	return 0;
}
