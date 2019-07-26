#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;


struct qnode{
	int a;
	qnode *next;
};

int qisempty(qnode ** head){
	if(*head==NULL)
		return 1;
	else
		return 0;
}

int qisoneelement(qnode ** head,qnode ** tail){
	if(*head==*tail)
		return 1;
	else
		return 0;
}

void enqueue(qnode ** head,qnode ** tail,int ele){
	qnode * e=new qnode();
	e->a=ele;
	e->next=NULL;

	if(qisempty(head)){
		(*head)=(*tail)=e;
	}
	else{
		(*tail)->next=e;
		(*tail)=e;		
	}
}

void qdisplay(qnode ** head){
	if(qisempty(head))
		cout<<"queue is empty\n";
	else{
		qnode * temp=*head;
		do{
			cout<<temp->a<<'\n';
			temp=temp->next;
		}while(temp!=NULL);
		//printf("%d\n",tail->a);
	}
}

void dequeue(qnode ** head,qnode ** tail){
	if(qisempty(head)){
		cout<<"queue is empty\n";
	}
	else if(qisoneelement(head,tail)){
		cout<<"deleted element is "<<(*head)->a;
		*head=*tail=NULL;
	}
	else{
		cout<<"..deleted element is "<<(*head)->a<<'\n';
		*head=(*head)->next;
	}
}
int main(){
	qnode * head=NULL,*tail=NULL;
	enqueue(&head,&tail,10);
	enqueue(&head,&tail,100);
	enqueue(&head,&tail,105);
	enqueue(&head,&tail,103);

	qdisplay(&head);
	cout<<"h"<<head->a<<'\n';

	dequeue(&head,&tail);
	qdisplay(&head);
	return 0;
}