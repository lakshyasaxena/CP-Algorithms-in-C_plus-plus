#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//     Given a Binary Tree
//     Find the maximum path Sum in the Tree
//
//     Consider the following Binary Tree for your reference
//
//                            root --> 5
//                                    / \
//                                   /   \
//                                  /     \
//                                 /       \
//                                /         \
//                               /           \
//                              /             \
//                             /               \
//                            /                 \
//                           10                 20
//                          /  \                / \
//                         /    \              /   \
//                        /      \            /     \
//                       /        \          /       \
//                      /          \        /         \
//                     /            \      /           \
//                    7              6    12           22
//                   / \            /                  / \
//                  /   \          /                  /   \
//                 4    18        50                 10    1
//                /                                 / \     \
//               /                                 /   \     \
//              3                                 5    15     2
//
//
//         In this binary Tree
//
//          5->20->22->10->15 is the maximum path sum
//          And sum = 72
//
class Birary_Tree_Node
{
public:
    ll data;
    Birary_Tree_Node *left=NULL;
    Birary_Tree_Node *right=NULL;
};
typedef Birary_Tree_Node bst;
bst* fill_binary_tree(bst *root);

void preorder_tree_treversal(bst *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder_tree_treversal(root->left);
    preorder_tree_treversal(root->right);
}

void inorder_tree_treversal(bst *root)
{
    if(root==NULL) return;
    inorder_tree_treversal(root->left);
    cout<<root->data<<" ";
    inorder_tree_treversal(root->right);
}
void traverse(vector <ll> &mp)
{
    for(int i=0;i<mp.size();i++)
    {
        cout<<mp[i]<<" ";
    }
}
//************************************************************************************************************
void find_maximum_path_sum(bst *root,ll &cs,ll &ms,vector <ll> &cp,vector <ll> &mp)
{
    if(root==NULL) return;
    cs+=root->data;
    cp.push_back(root->data);
    if(ms<cs)
    {
        ms=cs;
        mp.clear();
        mp=cp;
    }
    find_maximum_path_sum(root->left,cs,ms,cp,mp);
    if(root->left!=NULL)
    {
        cs-=root->left->data;
        cp.pop_back();
    }
    find_maximum_path_sum(root->right,cs,ms,cp,mp);
    if(root->right!=NULL)
    {
        cs-=root->right->data;
        cp.pop_back();
    }
}
//************************************************************************************************************
int main()
{
    ios_base::sync_with_stdio(false);
    bst *root=NULL;
    root=fill_binary_tree(root);

    cout<<"PRE-ORDER Tree traversal\n";
    preorder_tree_treversal(root);
    cout<<"\n\nIn-ORDER Tree traversal\n";
    inorder_tree_treversal(root);

    vector <ll> current_path;
    vector <ll> maximum_path;
    ll current_sum=0;
    ll maximum_sum=0;

    find_maximum_path_sum(root,current_sum,maximum_sum,current_path,maximum_path);
    cout<<"\n\nOne of the maximum path sum is as follows\n";
    traverse(maximum_path);
    cout<<"\nSum = "<<maximum_sum<<"\n\n";
    return 0;
}


// This function is just used for building binary tree
bst* fill_binary_tree(bst *root)
{
    bst *temp=new(bst);
    temp->data=5;
    root=temp;

    temp=new(bst);
    temp->data=10;
    root->left=temp;

    temp=new(bst);
    temp->data=20;
    root->right=temp;

    temp=new(bst);
    temp->data=7;
    root->left->left=temp;

    temp=new(bst);
    temp->data=6;
    root->left->right=temp;

    temp=new(bst);
    temp->data=12;
    root->right->left=temp;

    temp=new(bst);
    temp->data=22;
    root->right->right=temp;

    temp=new(bst);
    temp->data=4;
    root->left->left->left=temp;

    temp=new(bst);
    temp->data=18;
    root->left->left->right=temp;

    temp=new(bst);
    temp->data=50;
    root->left->right->left=temp;

    temp=new(bst);
    temp->data=10;
    root->right->right->left=temp;

    temp=new(bst);
    temp->data=1;
    root->right->right->right=temp;

    temp=new(bst);
    temp->data=5;
    root->right->right->left->left=temp;

    temp=new(bst);
    temp->data=15;
    root->right->right->left->right=temp;
    return root;
}
