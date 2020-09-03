#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//  You are given a BINARY TREE (may be BST)
//  You have to perform Spiral Order Tree Traversal
//  For reference consider the BST given below
//  Arrows will indicate you the Spiral Structure
//
//
//                          root-> 100   --------------------->
//                                 / \                         |
//                                /   \                        |
//                               /     \                       |
//                              /       \                      |
//                             /         \                     |
//                            /           \                    |
//                           /             \                   |                         Spiral  Traversal
//                          /               \                  |
//                         /                 \                 |                            100
//                        /                   \                |                            150 50
//       <------------   50                   150    <----------           --->             25 75 125 200
//       |              / \                   /  \                                          300 175 130 110 60 30 10
//       |             /   \                 /    \                                         5 12 40 105 115 128 160 180 250 310
//       |            /     \               /      \
//       |           /       \             /        \
//       |          /         \           /          \
//       |         /           \         /            \
//       ------>  25           75      125            200  ---------------->
//               / \           /       / \            / \                  |
//              /   \         /       /   \          /   \                 |
//             /     \       /       /     \        /     \                |
//            /       \     /       /       \      /       \               |
//    <------10        30  60      110       130  175      300  <-----------
//    |     / \          \         / \       /    / \       / \
//    |    /   \          \       /   \     /    /   \     /   \
//    --> 5     12        40     105  115 128   160  180 250   310
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
//*****************************************************************************
void spiral_tree_traversal(bst *root)
{
    stack <bst*> s1;   // odd level stack
    stack <bst*> s2;   // even level stack
    s1.push(root);
    while(!s1.empty()  ||  !s2.empty())
    {
        while(!s1.empty())
        {
            bst *temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)  // for even level stack we first push left child
            {
                s2.push(temp->left);
            }
            if(temp->right!=NULL)  // and then we push right child
            {
                s2.push(temp->right);
            }
        }
        cout<<"\n";
        while(!s2.empty())
        {
            bst *temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->right!=NULL)    // for odd level stack we first push right child
            {
                s1.push(temp->right);
            }
            if(temp->left!=NULL)  // and then we push left child
            {
                s1.push(temp->left);
            }
        }
        cout<<"\n";
    }
}
//*******************************************************************************
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
    cout<<"\nPRE-ORDER TRAVERSAL\n";
    preorder_traversal(root);
    cout<<"\nIN-ORDER TRAVERSAL\n";
    inorder_traversal(root);
    cout<<"\n\nSPIRAL TREE TRAVERSAL\n";
    spiral_tree_traversal(root);
    cout<<"\n\n";
    return 0;
}
