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
}*top1=NULL,*top2=NULL;

struct node* newNode1(struct bin_node *data)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;	
	return newnode;
}

void push1(struct bin_node *x)
{
	struct node *temp;
	temp=newNode1(x);
	if (top1==NULL)
	{
		top1=temp;
	}
	else
	{
		temp->link=top1;
		top1=temp;
	}
}

void push2(struct bin_node *x)
{
	struct node *temp;
	temp=newNode1(x);
	if (top2==NULL)
	{
		top2=temp;
	}
	else
	{
		temp->link=top2;
		top2=temp;
	}
}

struct bin_node * pop1()
{
	struct node *temp;
	temp=top1;
	if (top1!=NULL)
	{	
		top1=top1->link;
		return temp->data;
	}
}

struct bin_node * pop2()
{
	struct node *temp;
	temp=top2;
	if (top2!=NULL)
	{	
		top2=top2->link;
		return temp->data;
	}
}

int check_empty()
{
	if (top1==NULL)
		return 1;
	return 0;
}

void solve()
{
	struct bin_node *x,*y;
	while (check_empty()==0)
	{
		x=pop1();
		push2(x);
		if (x->left!=NULL)
			push1(x->left);
		if (x->right!=NULL)
			push1(x->right);
	}
	while (top2!=NULL)
	{
		printf("%d ",top2->data->data);
		top2=top2->link;
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
	push1(root);
	solve();
	return 0;
}