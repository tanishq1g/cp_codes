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

bst3node *  least_common_ancestor(int val1, int val2){
	bst3node * root=bstroot;
	while(1){
		if(val1 > root->val && val2 > root->val){
			if(root -> right == NULL )
				return root;
			root=root->right;
		}
		else if(val1 < root->val && val2 < root->val){
			if(root -> left == NULL )
				return root;
			root = root -> left;
		}
		else
			break;
	}
	return root;
}


int searchmin(bst3node * root, int val){
	int mi = root->val;
	while(1){
		if( val == root -> val)
			return mi;
		else if( val < root -> val){
			mi = min(root -> val , mi);
			if(root -> left == NULL )
				return -1;
			root = root -> left;
		}
		else if(val > root -> val){
			mi = min(root -> val , mi);
			if(root -> right == NULL )
				return -1;
			root = root -> right;
		}
	}
}

int searchmax(bst3node * root, int val){
	int ma = root->val;
	while(1){
		if( val == root -> val ) 
			return ma;
		else if( val < root -> val){
			ma = max(root -> val , ma);
			if(root -> left == NULL )
				return -1;
			root = root -> left;
		}
		else if(val > root -> val){
			ma = max(root -> val , ma);
			if(root -> right == NULL )
				return -1;
			root = root -> right;
		}
	}
}


int main(){
	bstroot=NULL;

	for(int i=0; i<1000; i++){
		insertbst( rand()%10000+1 );
	}
	preorderbst();
	cout<<'\n';
	int a,b;
	cout<<"enter val 1 : ";
	cin >> a;
	cout<<"\nenter val 2 :";
	cin >> b;
	cout<<"minimum element is "<<searchmin(least_common_ancestor(a,b),a)<<'\n'<<"maximum element is "<<searchmax(least_common_ancestor(a,b),b)<<'\n';
}