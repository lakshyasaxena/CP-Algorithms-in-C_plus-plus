#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//    Given a Binary Search Tree (BST)
//    You have to find the Kth largest and Kth smallest element in it
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
//      5th Largest element is  -> 80
//      2th Largest element is  -> 120
//
//      3nd smallest element is -> 25
//      5nd smallest element is -> 40
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
void Kth_Largest_Element(bst *root,ll &k,ll &element)
{
    if(root==NULL || k<=0) return;  // base condition
    Kth_Largest_Element(root->right,k,element);
    k--;
    if(k==0) element=root->data;
    if(k<=0) { return; }
    Kth_Largest_Element(root->left,k,element);
}

void Kth_smallest_Element(bst *root,ll &k,ll &element)
{
    if(root==NULL || k<=0) return;  //base condition
    Kth_smallest_Element(root->left,k,element);
    k--;
    if(k==0) {element=root->data;}
    if(k<=0) return;
    Kth_smallest_Element(root->right,k,element);
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
    ll element,k;

    element=-1;k=5;
    Kth_Largest_Element(root,k,element);
    cout<<"\n\n5 th largest element is = "<<element<<"\n";

    element=-1;k=14;
    Kth_Largest_Element(root,k,element);
    cout<<"\n14 th largest element is = "<<element<<"\n";

    element=-1;k=8;
    Kth_Largest_Element(root,k,element);
    cout<<"\n8 th largest element is = "<<element<<"\n";

    element=-1;k=8;
    Kth_smallest_Element(root,k,element);
    cout<<"\n8 th smallest element is = "<<element<<"\n";

    element=-1;k=1;
    Kth_smallest_Element(root,k,element);
    cout<<"\n1 st smallest element is = "<<element<<"\n";

    element=-1;k=14;
    Kth_smallest_Element(root,k,element);
    cout<<"\n14 th smallest element is = "<<element<<"\n";
    return 0;
}
