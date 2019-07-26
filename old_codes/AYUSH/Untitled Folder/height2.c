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

struct bin_node * dequeue()
{
	struct node *temp;
	temp=front;
	if (front==NULL)
	{
		front=rear=NULL;
		return NULL;
	}
	else if (front->link==NULL)
	{
		front=front->link;
		rear=NULL;
		return temp->data;
	}
	else
	{
		front=front->link;
		return temp->data;
	}
}

int find_length()
{
	struct node *x;
	x=front;
	int n=0;
	if (front == NULL)
		return 0;
	while (x!=NULL)
	{
		n++;
		x=x->link;
	}
	return n;
}

void solve()
{	
	struct bin_node *x;
	int n,height=-1;
	while(1)
	{
		n=find_length();
		if (n==0)
			break;
		else
			height++;
		while (n>0)
		{
			x=dequeue();
			if (x->left!=NULL)
				enqueue(x->left);
			if (x->right!=NULL)
				enqueue(x->right);
			n--;
		}
	}
	printf("Height = %d\n",height);
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
	solve();
	return 0;
}