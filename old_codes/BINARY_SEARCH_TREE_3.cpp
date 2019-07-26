#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;


struct bst3node{
	int val;
	bst3node *parent;
	bst3node *left;
	bst3node *right;
}*bstroot;


bst3node * insertbst1(bst3node *root,bst3node * ele, bst3node * cur){
	if(root==NULL){
		root=ele; 
		root->parent=cur;		
	}
	else if(ele -> val <= root -> val){
		root->left=insertbst1(root->left,ele,root);
	}
	else{
		root->right=insertbst1(root->right,ele,root);
	}
	return root;
}
void insertbst(int ele){
	bst3node * e = new bst3node();
	e -> val = ele;
	e -> left = NULL;
	e -> right = NULL;
	e -> parent = NULL;
	if(bstroot==NULL){
		bstroot=e; 
	}
	else{
		bst3node * temp=bstroot;
		insertbst1(temp,e,temp);
	}

}


void preorder1bst(bst3node * root){
	if ( root != NULL ){
		cout<<root -> val<<' ';
		preorder1bst( root -> left );
		preorder1bst( root -> right );
	}
}
void preorderbst(){
	bst3node * temp=bstroot;
	preorder1bst ( temp );
	cout<<'\n';
}

void postorder1bst ( bst3node * root ){
	if ( root != NULL ){
		postorder1bst ( root -> left ) ;
		postorder1bst ( root -> right ) ;
		cout << root -> val << ' ' ;
	}
}
void postorderbst(){
	bst3node * temp=bstroot;
	postorder1bst(temp);
	cout<<'\n';
}

void inorder1bst(bst3node * root){
	if ( root != NULL ){
		inorder1bst( root -> left );
		cout<<root -> val<<' ';
		inorder1bst( root -> right );
	}
}
void inorderbst(){
	bst3node * temp=bstroot;
	inorder1bst(temp);
	cout<<'\n';
}


int search1bst(bst3node * root,int ele){
	if ( root == NULL){
		return 0;
	}
	else{
		if(root -> val== ele){
			return 1;
		}
		else if(root -> val < ele){
			return search1bst(root -> right,ele);
		}
		else{
			return search1bst(root -> left,ele);
		}
	}
}
int searchbst(int val){
	bst3node * temp=bstroot;
	return search1bst(temp,val);
}


bst3node * minkeybst(bst3node * root){
	bst3node * temp= root;
	while(temp->left!=NULL)
		temp=temp -> left;
	return temp;
}

bst3node * maxkeybst(bst3node * root){
	bst3node * temp= root;
	while(temp->right!=NULL)
		temp=temp -> right;
	return temp;
}


bst3node * successorbst(bst3node * root){
	if(root->right!=NULL){
		return minkeybst(root->right);
	}
	else{
		bst3node * temp=root, * p= root->parent;
		while(p!=NULL && temp==p->right){
			temp=p;
			p=p->parent;
		}
		return p;
	}
}

bst3node * predecessorbst(bst3node * root){
	if(root->left!=NULL){
		return maxkeybst(root->left);
	}
	else{
		bst3node * temp=root, * p= root->parent;
		while(p!=NULL && temp==p->left){
			temp=p;
			p=p->parent;
		}
		return p;
	}
}


void deletebst(bst3node * root){
	bst3node * p = root -> parent , * c;
	if( root -> left == NULL && root -> right == NULL){
		if ( p == NULL )
			bstroot=NULL;
		else if( p -> left == root )
			p -> left = NULL;
		else
			p -> right = NULL;
	}
	else if ( root -> left == NULL ){
		c = root -> right;
		if ( p == NULL ){
			bstroot = c;
			c -> parent = NULL;
		}
		else if( p -> left == root ){
			p -> left = c;
			c -> parent = p;
		}
		else{
			p -> right = c;
			c -> parent = p;
		}
	}
	else if ( root -> right == NULL ){
		c = root -> left ;
		if ( p == NULL ){
			bstroot = c;
			c -> parent = NULL;
		}
		else if( p -> left == root ){
			p -> left = c;
			c -> parent = p;
		}
		else{
			p -> right = c;
			c -> parent = p;
		}
	}
	else{
		c=predecessorbst(root);
		root->val=c->val;
		deletebst(c);
	}
}


int main(){
	bstroot=NULL;
	insertbst(12);
	insertbst(130);
	insertbst(1);
	insertbst(10);
	insertbst(0);
	preorderbst();
	cout<<searchbst(1)<<'\n';
	preorderbst();
	insertbst(50);
	preorderbst();
	postorderbst();
	inorderbst();
 	cout<<successorbst(bstroot->left->left)->val<<'\n';
 	cout<<predecessorbst(bstroot)->val<<'\n';
 	deletebst(bstroot->left);
 	inorderbst();
	return 0;
}