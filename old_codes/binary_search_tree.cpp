#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;


struct bstnode{
	int val;
	bstnode *left;
	bstnode *right;
};
void bstdisplay(bstnode * r)
	{
		if( r != NULL )
		{
			bstdisplay(r->left);
			cout << r->val << endl;		
			bstdisplay(r->right);
		}
	}
// in this recursion root actully not changing and only its next value is passed on the function
bool searchbst(bstnode* root,int ele){
	if(root==NULL)
		return false;
	else if (root->val==ele)
		return true;
	else if (ele<=root->val)
		return (searchbst(root->left,ele));
	else
		return (searchbst(root->right,ele));
}

bstnode* insertbst(bstnode *root,int ele){
	bstnode * e=new bstnode();
	e->val=ele;
	e->left=NULL;
	e->right=NULL;
	if(root==NULL){
		root=e;
		return root;
	}
	else if(ele<=root->val){
		root->left=insertbst(root->left,ele);
	}
	else{
		root->right=insertbst(root->right,ele);
	}

}
int main(){
	bstnode *root=NULL;
	root=insertbst(root,12);
	root=insertbst(root,16);
	root=insertbst(root,11);
	root=insertbst(root,13);
	root=insertbst(root,13);
	root=insertbst(root,14);
	root=insertbst(root,15);
	root=insertbst(root,16);
	root=insertbst(root,116);
	root=insertbst(root,123);
	root=insertbst(root,13);
	bstdisplay(root);
	cout<<searchbst(root,11);
	return 0;
}