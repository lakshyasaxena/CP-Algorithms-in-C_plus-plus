#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//  You are given a BINARY TREE (may be BST)
//  You have to determine whether it is a height balanced
//  An empty tree is height-balanced. A non-empty binary tree T is balanced if:
//  1) Left subtree of T is balanced
//  2) Right subtree of T is balanced
//  3) The difference between heights of left subtree and right subtree is not more than 1.
//
//   Consider the given two BST
//
//                          root-> 100                                                       root->  100
//                                 / \                                                               / \
//                                /   \                                                             /   \
//                               /     \                                                           /     \
//                              /       \                                                         /       \
//                             /         \                                                       /         \
//                            /           \                                                     /           \
//                           /             \                                                   /             \
//                          /               \                                                 /               \
//                         /                 \                                               /                 \
//                        /                   \                                             /                   \
//                       50                   150                                          50                   150
//                      / \                   /  \                                        / \                   / \
//                     /   \                 /    \                                      /   \                 /   \
//                    /     \               /      \                                    /     \               /     \
//                   /       \             /        \                                  /       \             /       \
//                  /         \           /          \                                /         \           /         \
//                 /           \         /            \                              25         75         125        200
//                25           75      125            200                           /           /           \
//               / \           /       / \            / \                          /           /             \
//              /   \         /       /   \          /   \                        /           /               \
//             /     \       /       /     \        /     \                      10          60               130
//            /       \     /       /       \      /       \                                                  /
//           10        30  60      110       130  175      300                                               /
//          / \          \         / \       /    / \       / \                                             /
//         /   \          \       /   \     /    /   \     /   \                                           128
//        5     12        40     105  115 128   160  180 250   310
//
//     Out of given two BST
//    1- First one is height balanced
//    2- Second one is not height balanced
//
class Node_Of_Tree
{
public:
    ll data;
    Node_Of_Tree *left=NULL;
    Node_Of_Tree *right=NULL;
};
typedef Node_Of_Tree bst;
// bst stands for Binary Search TREE

void insert_in_bst(bst *root,bst *temp)
{
    if(root->data > temp->data) //left insertion case
    {
        if(root->left==NULL)
        {
            root->left=temp;
            return;
        }
        else
        {
            insert_in_bst(root->left,temp);
        }
    }
    else   // right insertion case
    {
        if(root->right==NULL)
        {
            root->right=temp;
            return;
        }
        else
        {
            insert_in_bst(root->right,temp);
        }
    }
}
void preorder_traversal(bst *root)
{
    if(root==NULL) return; // base case
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void inorder_traversal(bst *root)
{
    if(root==NULL) return; // base case
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
//*******************************************************************************
ll check_if_tree_is_balanced(bst* root,bool &status)
{
    if(root==NULL || status==false) return 0;
    ll lh=check_if_tree_is_balanced(root->left,status);
    ll rh=check_if_tree_is_balanced(root->right,status);
    if( abs (lh-rh) >1 ) { status=false;  }
    return (1 + max(lh,rh));
}
//*******************************************************************************
void delete_tree(bst *root)
{
    if(root==NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete(root);
}
int main()
{
    ios_base::sync_with_stdio(false);
    bst *root=NULL;  // pointer that will point root node
    ll nodes=24;
    vector <ll> input_nodes;  // in stands for input_nodes
    in.pb(100);   in.pb(50);
    in.pb(150);   in.pb(25);
    in.pb(75);    in.pb(125);
    in.pb(200);   in.pb(10);
    in.pb(30);    in.pb(60);
    in.pb(110);   in.pb(130);
    in.pb(175);   in.pb(300);
    in.pb(5);     in.pb(12);
    in.pb(40);    in.pb(105);
    in.pb(115);   in.pb(128);
    in.pb(160);   in.pb(180);
    in.pb(250);   in.pb(310);
    for(int i=0;i<nodes;i++)
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
    cout<<"First TREE\n";
    cout<<"\nPRE-ORDER TRAVERSAL\n";
    preorder_traversal(root);
    cout<<"\nIN-ORDER TRAVERSAL\n";
    inorder_traversal(root);
    bool status=true;
    check_if_tree_is_balanced(root,status);
    if(status==true)
    {
        cout<<"\n\nThe given TREE is height balanced\n\n";
    }
    else
    {
        cout<<"\n\nThe given TREE is not height balanced\n\n";
    }
    delete_tree(root);
    root=NULL;
    in.clear();
    nodes=11;
    in.pb(100);     in.pb(50);
    in.pb(150);     in.pb(25);
    in.pb(75);      in.pb(125);
    in.pb(200);     in.pb(10);
    in.pb(60);      in.pb(130);
    in.pb(128);
    for(int i=0;i<nodes;i++)
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
    cout<<"Second Tree\n";
    cout<<"\nPRE-ORDER TRAVERSAL\n";
    preorder_traversal(root);
    cout<<"\nIN-ORDER TRAVERSAL\n";
    inorder_traversal(root);
    check_if_tree_is_balanced(root,status);
    if(status==true)
    {
        cout<<"\n\nThe given TREE is height balanced\n\n";
    }
    else
    {
        cout<<"\n\nThe given TREE is not height balanced\n\n";
    }
    return 0;
}
