#include <bits/stdc++.h>
using namespace std;
#define in input_nodes
#define pb push_back
typedef long long ll;
//
//        Given a Binary Tree (may be BST)
//        You have to perform In-order Tree traversal on it and along with that you have to mention Level of each node
//
//        Consider the below Binary Tree for reference
//
//
//                          root-> 100                                 Level 1
//                                 / \
//                                /   \
//                               /     \
//                              /       \
//                             /         \
//                            /           \
//                           /             \
//                          /               \
//                         /                 \
//                        /                   \
//                       50                   150                      Level 2
//                      / \                   /  \
//                     /   \                 /    \
//                    /     \               /      \
//                   /       \             /        \
//                  /         \           /          \
//                 /           \         /            \
//                25           75      125            200              Level 3
//               / \           /       / \            / \
//              /   \         /       /   \          /   \
//             /     \       /       /     \        /     \
//            /       \     /       /       \      /       \
//           10        30  60      110       130  175      300         Level 4
//
class Tree_Node
{
public:
    ll data;
    Tree_Node *left=NULL;
    Tree_Node *right=NULL;
};
typedef Tree_Node bst;
void insert_in_tree(bst *root,bst *temp)
{
    if(root->data > temp->data)  // left insertion case
    {
        if(root->left==NULL)
        {
            root->left=temp;return;
        }
        insert_in_tree(root->left,temp);
    }
    else                         // right insertion case
    {
        if(root->right==NULL)
        {
            root->right=temp;return;
        }
        insert_in_tree(root->right,temp);
    }
}
void preorder_traversal(bst *root)
{
    if(root==NULL) return; // base condition
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
//*******************************************************************
void inorder_traversal(bst *root, ll &level)
{
    level++;
    if(root==NULL) return; // base condition
    inorder_traversal(root->left,level);
    level--;
    cout<<root->data<<" at level -> "<<level<<"\n";
    inorder_traversal(root->right,level);
    level--;
}
//*******************************************************************
int main()
{
    bst *root=NULL;           // pointer that will point to root
    ll nodes=14;
    vector <ll> input_nodes;
    in.pb(100);   in.pb(50);    in.pb(150);   in.pb(25);
    in.pb(75);    in.pb(125);   in.pb(200);   in.pb(10);
    in.pb(30);    in.pb(60);    in.pb(110);   in.pb(130);
    in.pb(175);   in.pb(300);
    for(int i=0;i<nodes;i++)
    {
        bst* temp=new(bst);
        temp->data=in[i];
        if(root==NULL)
        {
            root=temp;
            continue;
        }
        insert_in_tree(root,temp);
    }
    cout<<"Pre Order Traversal\n";
    preorder_traversal(root);
    ll level=0;
    cout<<"\n\nIn Order Traversal\n";
    inorder_traversal(root,level);
    return 0;
}
