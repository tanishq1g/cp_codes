#include <stdio.h>
#include <stdlib.h>

struct bin_node
{
	int data;
	struct bin_node *left;
	struct bin_node *right;
};

struct node
{
	struct bin_node *data;
	struct node *link;
}*front=NULL,*rear=NULL;

struct node* newNode1(struct bin_node *x)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->link=NULL;	
	return newnode;
}	

struct bin_node* newNode(int data)
{
	struct bin_node *newnode;
	newnode=(struct bin_node *)malloc(sizeof(struct bin_node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;	
	return newnode;
}	

void enqueue(struct bin_node *x)
{
	struct node *temp;
	temp=newNode1(x);
	if (rear==NULL)
		front=rear=temp;
	else
	{
		rear->link=temp;
		rear=temp;
	}	
}

void dequeue()
{
	struct node *temp;
	temp=front;
	if (front==NULL)
	{
		front=rear=NULL;
	}
	else
	{
		front=front->link;
		free(temp);
	}
}

int check_empty()
{
	if (front==NULL)
		return 1;
	return 0;
}

void solve(struct bin_node *newnode)
{	
	int flag;
	flag=0;
	while(flag!=1)
	{
		if (front->data->left!=NULL)
		enqueue(front->data->left);
		if (front->data->right!=NULL)
			enqueue(front->data->right);
		printf("%d ",front->data->data);
		dequeue();
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
	enqueue(root);
	solve(root);
	return 0;
}