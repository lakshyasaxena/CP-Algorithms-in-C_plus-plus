#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//  Given a Binary Tree
//  We have to find it's mirror image
//  For reference consider the below example
//  The idea is very simple. We traverse the tree in postorder fashion and for every node we swap it's left and right child pointer
//  after recursively converting its left subtree and right subtree first to mirror.
//
//
//                      root ->  12                        |                     root-> 12
//                              /  \                       |                           /  \
//                             /    \                      |                          /    \
//                            /      \                     |                         /      \
//                           /        \                    |                        /        \
//                          /          \                   |                       /          \
//                         /            \                  |                      /            \
//                        /              \                 |                     /              \
//                       10              20              Mirror                20              10
//                      /  \            /  \       --------------->>          /  \             / \
//                     /    \          /    \              |                  /    \           /   \
//                    /      \        /      \             |                 /      \         /     \
//                   5       11      15      22            |                /        \       /       \
//                  / \             /  \       \           |               22        15     11        5
//                 /   \           /    \       \          |              /          / \             / \
//                3     7         13    18      30         |             /          /   \           /   \
//                     /               /  \                |            /          /     \         /     \
//                    /               /    \               |           30         18     13       7       3
//                   6               17    19              |                     /  \              \
//                                                         |                    19  17              6
//
//
class Node_Of_Tree
{
public:
    ll data;
    Node_Of_Tree *left=NULL;
    Node_Of_Tree *right=NULL;
};
typedef Node_Of_Tree bst;
void input_in_bst(bst *root,bst *temp)
{
    if(root->data > temp->data)
    {
        if(root->left==NULL) { root->left=temp; return; }
        input_in_bst(root->left,temp);
    }
    else
    {
        if(root->right==NULL) { root->right=temp; return; }
        input_in_bst(root->right,temp);
    }
}
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
//*****************************************************************************************
void mirror_the_tree(bst *root)
{
    if(root==NULL) return;
    mirror_the_tree(root->left);
    mirror_the_tree(root->right);
    bst *temp=root->left;
    root->left=root->right;
    root->right=temp;
}
//*****************************************************************************************
int main()
{
    ios_base::sync_with_stdio(false);
    bst *root=NULL;    // pointer that will point the root node
    ll nodes=15;
    vector <ll> input_nodes;
    in.pb(12);     in.pb(10);     in.pb(20);     in.pb(5);
    in.pb(11);     in.pb(15);     in.pb(22);     in.pb(3);
    in.pb(7);      in.pb(13);     in.pb(18);     in.pb(30);
    in.pb(6);      in.pb(17);     in.pb(19);
    for(int i=0;i<nodes;i++)
    {
        bst *temp=new(bst);
        temp->data=in[i];
        if(root==NULL)
        {
            root=temp;continue;
        }
        input_in_bst(root,temp);
    }
    cout<<"\nPRE-ORDER TRAVERSAL\n";
    preorder_traversal(root);
    cout<<"\nIN-ORDER TRAVERSAL\n";
    inorder_traversal(root);

    mirror_the_tree(root);
    cout<<"\n\nAfter performing Mirror Operation\n";

    cout<<"\nPRE-ORDER TRAVERSAL\n";
    preorder_traversal(root);
    cout<<"\nIN-ORDER TRAVERSAL\n";
    inorder_traversal(root);
    return 0;
}
