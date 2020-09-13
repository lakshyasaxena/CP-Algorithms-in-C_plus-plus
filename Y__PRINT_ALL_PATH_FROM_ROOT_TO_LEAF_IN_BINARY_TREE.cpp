#include <bits/stdc++.h>
#define in input_nodes   // use it for efficiency
#define pb push_back    // use this macro for saving time and efficiency
using namespace std;
typedef long long ll;
//    You are given a Binary Tree (may be BST)
//    You have to print all possible root to leaf paths in the TREE
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
//      All possible paths are:
//     100  50  25  10  5
//     100  50  25  10  12
//     100  50  25  30  40
//     100  50  75
//     100  150  125  110  115
//     100  150  125  130
//     100  150  200  175  160
//     100  150  200  300
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
//*******************************************************************************************************
void discover_paths(bst *root,vector <ll> &current_path,vector <vector <ll > > &root_to_leaf_paths)
{
    if(root==NULL) // node with one child
    {
        return;
    }
    current_path.push_back(root->data);

    if(root->left == NULL && root->right == NULL) // leaf node
    {
        root_to_leaf_paths.push_back(current_path);
        current_path.pop_back();
        return;
    }

    discover_paths(root->left,current_path,root_to_leaf_paths);

    discover_paths(root->right,current_path,root_to_leaf_paths);

    current_path.pop_back();
}
//*******************************************************************************************************
void traverse_all_paths(vector <vector <ll > > &v1)
{
    cout<<"Root to leaf all possible paths : \n\n";
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v1[i].size();j++)
        {
            cout<<v1[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    bst *root=NULL;
    ll nodes=18;
    vector <ll> input_nodes;   // macro used for it is -> in
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
    cout<<"\nPre-Order Traversal\n";
    preorder_traversal(root);
    cout<<"\n\nIn-Order Traversal\n";
    inorder_traversal(root);
    cout<<"\n\n";

    vector <vector <ll > > root_to_leaf_paths;
    vector <ll> current_path;
    discover_paths(root,current_path,root_to_leaf_paths);
    traverse_all_paths(root_to_leaf_paths);
    return 0;
}
