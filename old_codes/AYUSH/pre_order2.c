#include <stdio.h>
#include <stdlib.h>

struct bin_node
{
	int data;
	struct bin_node *left;
	struct bin_node *right;
};

struct bin_node* newNode(int data)
{
	struct bin_node *newnode;
	newnode=(struct bin_node *)malloc(sizeof(struct bin_node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;	
	return newnode;
}

struct node
{
	struct bin_node *data;
	struct node *link;
}*top=NULL;

struct node* newNode1(struct bin_node *data)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;	
	return newnode;
}

void push(struct bin_node *x)
{
	struct node *temp;
	temp=newNode1(x);
	if (top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->link=top;
		top=temp;
	}
}

struct bin_node * pop()
{
	struct node *temp;
	temp=top;
	if (top!=NULL)
	{	
		top=top->link;
		return temp->data;
	}
}

int check_empty()
{
	if (top==NULL)
		return 1;
	return 0;
}

void solve()
{
	int flag;
	flag=0;
	struct bin_node *x;
	while(flag!=1)
	{
		x=pop();
		printf("%d ",x->data);
		if (x->right!=NULL)
			push(x->right);
		if (x->left!=NULL)
			push(x->left);
		flag=check_empty();
	}
}

int main()
{
	struct bin_node *root, *newnode6, *newnode5, *newnode4, *newnode3, *newnode2, *newnode1;
	newnode6=newNode(6);
	newnode5=newNode(5);
	newnode4=newNode(4);
	newnode3=newNode(3);
	newnode2=newNode(2);
	newnode1=newNode(1);
	root=newNode(0);
	root->left=newnode1;
	root->right=newnode2;
	newnode1->left=newnode3;
	newnode1->right=newnode4;
	newnode2->right=newnode5;
	newnode4->left=newnode6;
	push(root);
	solve();
	return 0;
}