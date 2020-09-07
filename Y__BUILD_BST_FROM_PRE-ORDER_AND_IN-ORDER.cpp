#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
//
//   Given Pre-Order and In-order of Binary Search Tree
//   We have to build Binary Search Tree from them
//
//
//   The idea is to use the divide and conquer technique.
//
//   Algorithm ( Took Algorithm from Geeks for Geeks)
//   1) Pick an element from Preorder. Increment a Preorder Index Variable
//      (preIndex in below code) to pick next element in next recursive call.
//   2) Create a new tree node tNode with the data as picked element.
//   3) Find the picked element’s index in Inorder. Let the index be inIndex.
//   4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
//   5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
//   6) return tNode.
//
//   Consider the following example:
//
//   Pre-Order =   [ 12 , 10 , 5 , 3 , 7 , 6 , 11 , 20 , 15 , 13 , 18 , 17 , 19 , 22 , 30 ]
//   In-Order  =   [ 3 , 5 , 6 , 7 , 10 , 11 , 12 , 13 , 15 , 17 , 18 , 19 , 20 , 22 , 30 ]
//
//                                                root -> 12
//                                                       _/\_
//                                                     _/    \_
//                                                   _/        \_
//                                                  /            \
//                                                 10             20
//                                               _/  \           /  \
//                                             _/     \_       _/    \_
//                                            /         \     /        \
//                                           5          11   15        22
//                                         _/ \_            / \          \
//                                       _/     \_         /   \          \
//                                      /         \       /     \          \
//                                     3           7     13     18         30
//                                                /            /  \
//                                               6            17  19
//
//
class Binary_Search_Tree_Node
{
public:
    ll data;
    Binary_Search_Tree_Node *left=NULL;
    Binary_Search_Tree_Node *right=NULL;
};
typedef Binary_Search_Tree_Node bst;

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

bst* build_bst(ll low,ll up,vector <ll> &pre,vector <ll> &in,ll &index,bst *root)
{
    if(low>up)
    {
        root=NULL;
        return root;
    }
    ll node=pre[++index];
    int k;
    for(k=low;k<=up;k++)
    {
        if(node==in[k]) break;
    }
    bst* temp=new (bst);
    temp->data=node;
    root=temp;
    root->left=build_bst(low,k-1,pre,in,index,root->left);
    root->right=build_bst(k+1,up,pre,in,index,root->right);
    return root;
}
void traverse(vector <ll> &v1)
{
    for(int i=0;i<v1.size();i++) cout<<v1[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    vector <ll> pre;  // pre-order of tree
    vector <ll> in;   // in-order  of tree
    pre.pb(12);  pre.pb(10);  pre.pb(5);   pre.pb(3);
    pre.pb(7);   pre.pb(6);   pre.pb(11);  pre.pb(20);
    pre.pb(15);  pre.pb(13);  pre.pb(18);  pre.pb(17);
    pre.pb(19);  pre.pb(22);  pre.pb(30);
    //*************************************************
    in.pb(3);   in.pb(5);  in.pb(6);   in.pb(7);
    in.pb(10);  in.pb(11); in.pb(12);  in.pb(13);
    in.pb(15);  in.pb(17); in.pb(18);  in.pb(19);
    in.pb(20);  in.pb(22);  in.pb(30);
    //*************************************************

    cout<<"Pre-Order Array\n";
    traverse(pre);
    cout<<"\n\nIn-Order Array\n";
    traverse(in);
    ll low=0;
    ll up=in.size()-1;
    ll index=-1;

    bst *root=NULL;
    root=build_bst(low,up,pre,in,index,root);

    cout<<"\n\nBinary Search Tree\n";
    cout<<"\nPre-order Tree Traversal\n";
    preorder_traversal(root);
    cout<<"\nIn-order Tree Traversal\n";
    inorder_traversal(root);
    cout<<"\n\n";
    return 0;
}
