#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

struct snode{
	int a;
	snode* next;
}*top;

int sisempty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}

int sisoneelement(){
	if(top->next==NULL)
		return 1;
	else
		return 0;
}

void sdisplay(){
	if(sisempty())
		printf("empty stack\n");
	else{
		snode*curr;
		curr=top;
		do{
			printf("%d\n",curr->a);
			curr=curr->next;
		}while(curr!=NULL);
		//printf("%d\n",tail->a);
	}
}

void push(int ele){
	snode *e=new snode();
	e->a=ele;
	e->next=NULL;
	if(sisempty()){
		top=e;
		//printf("%d\n",tail->a);
	}
	else{
		e->next=top;
		top=e;
	}
}

void pop(){
	if(sisempty()){
		printf("stack is empty\n");
	}
	else if(sisoneelement()){
		printf("deleted element is %d",top->a);
		top=NULL;
	}
	else{
		printf("deleted element is %d",top->a);
		top=top->next;
	}
}



int main(){
	snode * top=NULL;
	
	return 0;
}