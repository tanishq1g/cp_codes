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

struct avlnode{
	int val;
	int height;
	avlnode *parent;
	avlnode *left;
	avlnode *right;
} * avlroot;


avlnode * insertavl1(avlnode *root,avlnode * ele, avlnode * cur){
	if(root==NULL){
		root=ele; 
		root->parent=cur;		
	}
	else if(ele -> val <= root -> val){
		root->left=insertavl1(root->left,ele,root);
	}
	else{
		root->right=insertavl1(root->right,ele,root);
	}
	return root;
}
void insertavl(int ele){
	avlnode * e = new avlnode();
	e -> val = ele;
	e -> left = NULL;
	e -> right = NULL;
	e -> parent = NULL;
	e -> height = 1;
	if(avlroot==NULL){
		avlroot=e; 
	}
	else{
		bst3node * temp=avlroot;
		insertavl1(temp,e,temp);
	}
}

 
int main(){
	avlroot = NULL;

}