#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;


struct node{
	int val;
	node *next;
};

struct arr{
	node *head;
}a[10000];

void add_ele(){
	int i;
	for(i=0;i<10000;i++)
		a[i].head=NULL;
	
	for(i=1;i<=1000000;i++){
		int index=rand() % 10000;
		int ele = rand() % 1000;
		node *curr=new node;
		curr->val=ele;
		curr->next=NULL;
		if(a[index].head==NULL)
			a[index].head=curr;
		else{
			node *n;
			n=a[index].head;
			while(n->next!=NULL)
				n=n->next;
			n->next=curr;
		}
			
	}
	
}


void reduce(){
	int i;
	for(i=0;i<10000;i++){
		if(a[i].head!=NULL) {
			if(a[i].head->next!=NULL){
				int flag=0;
				node *n;
				n=a[i].head;
				while(n!=NULL){
					if(n->val%2==0){
						flag=1;
						break;
					}
					else 
						n=n->next;
				}
				
				if(flag==1){
					int max=n->val;
					node *max_node;
					max_node=n;
					while(n!=NULL){
						if( n->val%2==0 && n->val>max){
							max=n->val;
							max_node=n;
							n=n->next;
						}
						else
							n=n->next;
							
					}
					a[i].head=max_node;
					a[i].head->next=NULL;
					
				}
				
				else{
					node *min_node;
					node *new1;
					new1=a[i].head;
					min_node=a[i].head;
					int min=a[i].head->val;
					while(new1!=NULL){
						if( new1->val<min){
							min=new1->val;
							min_node=new1;
							new1=new1->next;
							
						}
						else
							new1=new1->next;
							
					}
					
					a[i].head=min_node;
					a[i].head->next=NULL;	
				}	
			}
		}
	}
}

int final_ele(){
	int i;
	int min=10000,max=-1;
	for(i=0;i<10000;i++){
		if(a[i].head!=NULL) {
			if(a[i].head->val%2==0 && a[i].head->val>max){
				max=a[i].head->val;
			}
			else if(a[i].head->val%2!=0 && a[i].head->val<min){
				min=a[i].head->val;
			}
		}
	}
	
	if(max!=-1)
		return max;
	else 
		return min;

}

int main(){
	add_ele();
	reduce();
	int b=final_ele();
	cout<<b;
	return 0;
}