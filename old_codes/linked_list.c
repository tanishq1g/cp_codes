#include <stdio.h>
#include <stdlib.h>

struct node{
	int a;
	struct node* next;
}*top;

int isempty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}

int isoneelement(){
	if(top->next==NULL)
		return 1;
	else
		return 0;
}

void display(){
	if(isempty())
		printf("empty stack\n");
	else{
		struct node*curr;
		curr=top;
		do{
			printf("%d\n",curr->a);
			curr=curr->next;
		}while(curr!=NULL);
		//printf("%d\n",tail->a);
	}
}

void push(int ele){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->a=ele;
	new->next=NULL;
	if(isempty()){
		top=new;
		//printf("%d\n",tail->a);
	}
	else{
		
		
		if(isoneelement()){
			struct node *curr=top;
			if(curr->a < ele){
				new->next=curr;
				top=new;
			}
			else{
				curr->next=new;
			}
			display();
		}
		else{
			if(top->a <ele){
				new->next=top;
				top=new;
				display();
			}
			else{
				struct node *curr=top,*temp=top->next;
				do{
					if(temp->a < ele){
						curr->next=new;
						new->next=temp;
						display();
						break;
					}
					else{
							curr=curr->next;
							temp=temp->next;
							if(temp==NULL){
								curr->next=new;
								display();
								break;
							}
					
					}
				}while(temp!=NULL);
		
			}
		}//printf("%d\n",head->a);
	}
}

void pop(){
	if(isempty()){
		printf("stack is empty\n");
	}
	else if(isoneelement()){
		printf("deleted element is %d",top->a);
		top=NULL;
	}
	else{
		printf("deleted element is %d",top->a);
		top=top->next;
	}
}


int menu(){
	int choice;
	printf("select the correct choice\n1)push\n2)pop\n3)disply\nenter choice : ");
	scanf("%d",&choice);
	return choice;
}

int main(){
	top=NULL;
	int choice;
	char ch;	
	do{
		choice=menu();
		switch(choice){
			case 1:	
				printf("enter the element you want to enter :");
				int ele;
				scanf("%d",&ele);
				push(ele);
				break;
			case 2:
				pop();
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