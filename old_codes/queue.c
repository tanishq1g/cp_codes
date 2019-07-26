#include <stdio.h>
#include <stdlib.h>

int menu();

struct node{
	int a;
	struct node *next;
}*head,*tail;

int isempty(){
	if(head==NULL)
		return 1;
	else
		return 0;
}

int isoneelement(){
	if(head==tail)
		return 1;
	else
		return 0;
}

void enqueue(int ele){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->a=ele;
	new->next=NULL;
	if(isempty()){
		head=tail=new;
		//printf("%d\n",tail->a);
	}
	else{
		tail->next=new;
		tail=new;		
		//printf("%d\n",head->a);
	}
}

void dequeue(){
	if(isempty()){
		printf("queue is empty\n");
	}
	else if(isoneelement()){
		printf("deleted element is %d",head->a);
		head=tail=NULL;
	}
	else{
		printf("deleted element is %d",tail->a);
		head=head->next;
	}
}

void display(){
	if(isempty())
		printf("empty queue\n");
	else{
		struct node*curr;
		curr=head;
		do{
			printf("%d\n",curr->a);
			curr=curr->next;
		}while(curr!=NULL);
		//printf("%d\n",tail->a);
	}
}

int main(){
	head=tail=NULL;
	int choice;
	char ch;	
	do{
		choice=menu();
		switch(choice){
			case 1:	
				printf("enter the element you want to enter :");
				int ele;
				scanf("%d",&ele);
				enqueue(ele);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
		}
		printf("\ndo you want to continue(y/n):");
		scanf("%s",&ch);
	}while(ch=='y');
	return 0;
}
int menu(){
	int choice;
	printf("select the correct choice\n1)enqueue\n2)dequeue\n3)disply\nenter choice : ");
	scanf("%d",&choice);
	return choice;
}