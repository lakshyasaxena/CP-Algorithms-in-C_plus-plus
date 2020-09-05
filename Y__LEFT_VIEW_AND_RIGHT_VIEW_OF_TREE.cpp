#include <bits/stdc++.h>
using namespace std;
#define in input_nodes
#define pb push_back
typedef long long ll;
//
//        Given a Binary Tree (may be BST)
//        You have to print Left view and Right view of Binary Tree
//        Left view of a Binary Tree is set of nodes visible when tree is visited from left side.
//        Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.
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
//                          \                /
//                           \              /
//                            \            /
//                            70         128                           Level 5
//                                       /
//                                      /
//                                     /
//                                    127                              Level 6
//
//
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
void inorder_traversal(bst *root)
{
    if(root==NULL) return; // base condition
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
//***************************************************************************************
void left_view(bst *root,ll &level,ll &maxi)
{
    level++;
    if(root==NULL) return;
    if(maxi<level)
    {
        maxi=level;
        cout<<root->data<<" ";
    }
    left_view(root->left,level,maxi);
    level--;
    left_view(root->right,level,maxi);
    level--;
}

void right_view(bst *root,ll &level,ll &maxi)
{
    level++;
    if(root==NULL) return;
    if(maxi<level)
    {
        maxi=level;
        cout<<root->data<<" ";
    }
    right_view(root->right,level,maxi);
    level--;
    right_view(root->left,level,maxi);
    level--;
}
//***************************************************************************************
int main()
{
    bst *root=NULL;           // pointer that will point to root
    ll nodes=17;
    vector <ll> input_nodes;
    in.pb(100);   in.pb(50);    in.pb(150);   in.pb(25);
    in.pb(75);    in.pb(125);   in.pb(200);   in.pb(10);
    in.pb(30);    in.pb(60);    in.pb(110);   in.pb(130);
    in.pb(175);   in.pb(300);   in.pb(70);    in.pb(128);    in.pb(127);
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
    cout<<"\n\nIn Order Traversal\n";
    inorder_traversal(root);
    cout<<"\n\nLeft view Of Binary Tree\n";

    ll level=0; ll maxi=0;

    left_view(root,level,maxi);
    cout<<"\n\nRight view Of Binary Tree\n";

    level=0; maxi=0;

    right_view(root,level,maxi);
    cout<<"\n\n";
    return 0;
}
