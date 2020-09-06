#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//    Given a Binary Tree (may be BST)
//    You have to print all it's leaf nodes and internal nodes separately
//
//    For reference, consider the BST given below
//
//
//                          root ->   60
//                                   /  \
//                                  /    \
//                                _/      \_
//                               /          \
//                             _/            \_
//                            /                \
//                           /                  \
//                         30                   100
//                        /  \                  /  \
//                       /    \                /    \
//                      /      \              /      \
//                     5       50            80      120
//                    /\       /\           /        / \
//                   /  \     /  \         /        /   \
//                  1   25   40  55       65       110  130
//
//
//            Leaf   Nodes   are -> 1 25 40 55 65 110 130
//            Internal Nodes are -> 60 30 5 50 100 80 120
//

class Binary_Search_Tree_Node
{
public:
    ll data;
    Binary_Search_Tree_Node *left=NULL;
    Binary_Search_Tree_Node *right=NULL;
};
typedef Binary_Search_Tree_Node bst;

void insert_in_bst(bst *root,bst *temp)
{
    if(root->data > temp->data)  // left case
    {
        if(root->left==NULL)
        {
            root->left=temp;
            return;
        }
        insert_in_bst(root->left,temp);
    }
    else // right case
    {
        if(root->right==NULL)
        {
            root->right=temp;
            return;
        }
        insert_in_bst(root->right,temp);
    }
}

//*********************************************************************************************
void print_leaf_nodes(bst *root,ll &count_leaf)
{
    if(root==NULL) return;
    print_leaf_nodes(root->left,count_leaf);
    print_leaf_nodes(root->right,count_leaf);
    if(root->left==NULL && root->right==NULL)
    {
        count_leaf++;
        cout<<root->data<<" ";
    }
}

void print_internal_nodes(bst *root,ll &count_internal)
{
    if(root==NULL) return;
    print_internal_nodes(root->left,count_internal);
    print_internal_nodes(root->right,count_internal);
    if(root->left!=NULL || root->right!=NULL)
    {
        count_internal++;
        cout<<root->data<<" ";
    }
}
//*********************************************************************************************

void preorder_traversal(bst *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(bst *root)
{
    if(root==NULL) return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    bst *root=NULL;
    ll nodes=14;
    vector <ll> input_nodes;
    in.pb(60);     in.pb(30);     in.pb(100);    in.pb(5);     in.pb(50);     in.pb(80);     in.pb(120);    in.pb(1);
    in.pb(25);     in.pb(40);     in.pb(55);     in.pb(65);    in.pb(110);    in.pb(130);
    for(int i=0;i<in.size();i++)
    {
        bst *temp=new(bst);
        temp->data=in[i];
        if(root==NULL)
        {
            root=temp;
            continue;
        }
        insert_in_bst(root,temp);
    }
    cout<<"Pre-Order Tree traversal\n";
    preorder_traversal(root);
    cout<<"\n\nIn-Order Tree traversal\n";
    inorder_traversal(root);

    cout<<"\n\nLeaf nodes are -> ";
    ll count_leaf=0;
    print_leaf_nodes(root,count_leaf);
    cout<<"\nThere are "<<count_leaf<<" leaf nodes";

    cout<<"\n\nInternal nodes are -> ";
    ll count_internal=0;
    print_internal_nodes(root,count_internal);
    cout<<"\nThere are "<<count_internal<<" internal nodes\n\n";
    return 0;
}


