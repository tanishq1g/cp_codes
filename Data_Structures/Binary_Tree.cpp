#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

// TREE DECLARATION
struct node
{
        int data;                 //Data element
        struct node * left;          //Pointer to left node
        struct node * right;         //Pointer to right node
};

// CREATE NEW NODE
struct node * newnode(int element){
    struct node * temp=(node * )malloc(sizeof(node));
    temp->data=element;
    temp->left=temp->right=NULL;
    return temp;
}

// HIEGHT OF THE TREE
int maxDepth(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
            /* compute the depth of each subtree */
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);

            /* use the larger one */
            if (lDepth > rDepth)
                return(lDepth+1);
            else
                return(rDepth+1);
    }
}
void main(){

    // simple node
    struct node root;

    // pointer to node
    struct node * root;
    root = (node *)malloc(sizeof(node));


}