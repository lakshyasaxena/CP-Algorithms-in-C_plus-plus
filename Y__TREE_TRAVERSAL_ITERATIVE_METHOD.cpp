#include <bits/stdc++.h>
#define in input_nodes   // use it for efficiency
#define pb push_back    // use this macro for saving time and efficiency
using namespace std;
typedef long long ll;
//    You are given a Binary Tree (may be BST)
//    You have to perform Iterative Tree Traversal on them
//    1. Pre-Order   Iterative Tree Traversal
//    2. In-Order    Iterative Tree Traversal
//    3. Post-Order  Iterative Tree Traversal
//
//    Consider the below given BST for reference
//
//
//                         root->100
//                              /   \
//                             /     \
//                            /       \
//                           /         \
//                          /           \
//                         /             \
//                        /               \
//                       /                 \
//                      50                 150
//                     / \                 /  \
//                    /   \               /    \
//                   /     \             /      \
//                  /       \           /        \
//                 /         \         /          \
//               25          75       125          200
//               / \                 /   \         / \
//              /   \               /     \       /   \
//            10     30            110    130   175   300
//           /  \      \             \          /
//          /    \      \             \        /
//         5     12     40            115    160
//
//
//
class Node_Of_Binary_Tree
{
public:
    ll data;
    Node_Of_Binary_Tree *left;  // left pointer
    Node_Of_Binary_Tree *right; // right pointer
    Node_Of_Binary_Tree()
    {
        data=0;
        left=right=NULL;
    }
};
typedef Node_Of_Binary_Tree bst;
// bst stands for Binary Search Tree

void insert_into_bst(bst *root,bst* temp)
{
    if(root->data > temp->data) // left case
    {
        if(root->left==NULL)
        {
            root->left=temp;
            return;
        }
        else
        {
            insert_into_bst(root->left,temp);
        }
    }
    else  // right case
    {
        if(root->right==NULL)
        {
            root->right=temp;
            return;
        }
        else
        {
            insert_into_bst(root->right,temp);
        }
    }
}
//*******************************************************************************************************
void preorder_traversal_iterative_method(bst *root)
{
    cout<<"Pre-Order traversal Iterative Method\n";
    stack <bst *> s1;
    bst *curr=root;
    while(!s1.empty() || curr!=NULL)
    {
        while(curr!=NULL)
        {
            s1.push(curr);
            cout<<curr->data<<" ";
            curr=curr->left;
        }
        curr=s1.top()->right;
        s1.pop();
    }
    cout<<"\n\n";
}
void inorder_traversal_iterative_method(bst *root)
{
    cout<<"In-Order Traversal Iterative Method\n";
    stack <bst *> s1;
    bst *curr=root;
    while(!s1.empty() || curr!=NULL)
    {
        while(curr!=NULL)
        {
            s1.push(curr);
            curr=curr->left;
        }
        cout<<s1.top()->data<<" ";
        curr=s1.top()->right;
        s1.pop();
    }
    cout<<"\n\n";
}
void postorder_traversal_iterative_method(bst *root)
{
    cout<<"Post-Order Traversal Iterative Method\n";
    if(root==NULL) return;
    stack <bst *> s1;
    stack <bst *> s2;
    bst *curr=root;
    s1.push(curr);
    while(!s1.empty())
    {
        curr=s1.top();
        s2.push(s1.top());
        s1.pop();
        if(curr->left!=NULL)
        {
            s1.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            s1.push(curr->right);
        }
    }
    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
    cout<<"\n\n";
}
//*******************************************************************************************************

int main()
{
    bst *root=NULL;
    ll nodes=18;
    vector <ll> input_nodes;   // macro used for it is -> in , and pb stands for push_back
    in.pb(100);     in.pb(50);      in.pb(150);     in.pb(25);      in.pb(75);      in.pb(125);     in.pb(200);     in.pb(10);
    in.pb(30);      in.pb(110);     in.pb(130);     in.pb(175);     in.pb(300);     in.pb(5);       in.pb(12);      in.pb(40);
    in.pb(115);     in.pb(160);
    for(int i=0;i<nodes;i++)
    {
        bst* temp=new(bst);
        temp->data=in[i];
        if(root==NULL)
        {
            root=temp; continue;
        }
        insert_into_bst(root,temp);
    }
    preorder_traversal_iterative_method(root);
    inorder_traversal_iterative_method(root);
    postorder_traversal_iterative_method(root);
    return 0;
}


//  Below are the recursive Method
/*
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
void postorder_traversal(bst *root)
{
    if(root==NULL) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}
*/
