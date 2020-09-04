#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//  Given two Binary Trees
//  We have determine if they are mirror image of each other
//  Two trees are to be mirror images, if the following three conditions are followed

//   1: Their root node’s key must be same
//   2: Left subtree of root of first and right subtree root of second are mirror.
//   3: Right subtree of first and left subtree of second are mirror.
//
//     The idea is very simple. We traverse both the trees in in-order fashion and store them.
//     Reverse any one of them and then perform comparison.
//     If they both are same then we say that they both are mirror image.
//
//    For reference consider the below example
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
//                       10              20                |                    20              10
//                      /  \            /  \               |                   /  \             / \
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
//       The above two trees are mirror image of each other
//

class Node_Of_Tree
{
public:
    ll data;
    Node_Of_Tree *left=NULL;
    Node_Of_Tree *right=NULL;
};
typedef Node_Of_Tree bst;
bst* insert_in_tree2(bst *root2);  // this function is just inserting nodes in tree2, nothing to do with mirror function
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
void inorder_traversal(bst *root,vector <ll> &v1)
{
    if(root==NULL) return;
    inorder_traversal(root->left,v1);
    v1.push_back(root->data);
    cout<<root->data<<" ";
    inorder_traversal(root->right,v1);
}
//*****************************************************************************************
bool check_mirror(vector <ll> &tree1, vector <ll> &tree2)
{
    if(tree1.size()!=tree2.size()) return false;
    int first=-1;
    int last=tree1.size();
    while( first != (tree1.size()-1) )
    {
        if(tree1[++first] != tree2[--last]) return false;
    }
    return true;
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
    cout<<"     TREE 1";
    cout<<"\n PRE-ORDER TRAVERSAL\n ";
    preorder_traversal(root);
    cout<<"\n IN-ORDER TRAVERSAL\n ";
    vector <ll> tree1;
    inorder_traversal(root,tree1);

    bst *root2=NULL;
    root2=insert_in_tree2(root2);

    vector <ll> tree2;
    cout<<"\n\n     TREE 2";
    cout<<"\n PRE-ORDER TRAVERSAL\n ";
    preorder_traversal(root2);
    cout<<"\n IN-ORDER TRAVERSAL\n ";
    inorder_traversal(root2,tree2);
    bool check=check_mirror(tree1,tree2);
    if(check==false)
    {
        cout<<"\n\nTrees are not mirror image of each other\n";
    }
    else
    {
        cout<<"\n\nTrees are mirror image of each other\n";
    }
    cout<<"\n\n";
    return 0;
}


//  This function is just inserting nodes in tree 2, nothing to do with mirror function
bst* insert_in_tree2(bst *root2)
{
    bst *temp=new(bst);
    temp->data=12;
    root2=temp;
    temp=new(bst);
    temp->data=20;
    root2->left=temp;
    temp=new(bst);
    temp->data=22;
    root2->left->left=temp;
    temp=new(bst);
    temp->data=30;
    root2->left->left->left=temp;
    temp=new(bst);
    temp->data=15;
    root2->left->right=temp;
    temp=new(bst);
    temp->data=18;
    root2->left->right->left=temp;
    temp=new(bst);
    temp->data=19;
    root2->left->right->left->left=temp;
    temp=new(bst);
    temp->data=17;
    root2->left->right->left->right=temp;
    temp=new(bst);
    temp->data=13;
    root2->left->right->right=temp;
    temp=new(bst);
    temp->data=10;
    root2->right=temp;
    temp=new(bst);
    temp->data=11;
    root2->right->left=temp;
    temp=new(bst);
    temp->data=5;
    root2->right->right=temp;
    temp=new(bst);
    temp->data=7;
    root2->right->right->left=temp;
    temp=new(bst);
    temp->data=6;
    root2->right->right->left->right=temp;
    temp=new(bst);
    temp->data=3;
    root2->right->right->right=temp;
    return root2;
}

