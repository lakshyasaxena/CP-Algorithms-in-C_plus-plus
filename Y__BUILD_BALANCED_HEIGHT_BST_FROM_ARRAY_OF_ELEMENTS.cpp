#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//      Given a sorted array
//      You have to construct Balanced Height Binary Search Tree using elements of the array

//       Procedure
//
//       1) Get the Middle of the array and make it root.
//       2) Recursively do same for left half and right half.
//           a) Get the middle of left half and make it left child of the root  created in step 1.
//           b) Get the middle of right half and make it right child of the root created in step 1.
//
//       The idea is to use divide and conquer technique
//       Consider this example:
//
//             index ->  0 1 2  3  4 5 6
//               arr = [ 1 2 3 (4) 5 6 7 ]                                 root -> 4
//                              |                                                 / \
//                      ________|__________                                      /   \
//                     |                   |                                    /     \
//                  1 (2) 3             5 (6) 7        ---->>>                 /       \
//                     |                   |                                  /         \
//                 ____|____           ____|____                             2           6
//                |         |         |         |                           / \         / \
//               (1)       (3)       (5)       (7)                         /   \       /   \
//                                                                        1     3     5     7
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
    else  // right case
    {
        if(root->right==NULL)
        {
            root->right=temp;
            return;
        }
        insert_in_bst(root->right,temp);
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

void reorder_nodes(vector <ll> &c_f,vector <ll> &in,ll low,ll high)
{
    if(low>high)  // base case
    {
        return;
    }
    ll mid=(low+high)/2;
    c_f.push_back(in[mid]);
    reorder_nodes(c_f,in,low,mid-1);
    reorder_nodes(c_f,in,mid+1,high);
}

bst* build_balanced_height_bst(bst *root,vector <ll> &in)
{
    vector <ll> correct_format;
    ll low=0;
    ll high=in.size()-1;
    reorder_nodes(correct_format,in,low,high);
    for(int i=0;i<correct_format.size();i++)
    {
        bst *temp=new(bst);
        temp->data=correct_format[i];
        if(root==NULL)
        {
            root=temp;
            continue;
        }
        insert_in_bst(root,temp);
    }
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll nodes;
    nodes=17;
    vector <ll> input_nodes;
    for(int i=1;i<=nodes;i++) input_nodes.push_back(i);

    bst *root=NULL;
    root=build_balanced_height_bst(root,input_nodes);

    cout<<"Pre-Order Tree Traversal\n";
    preorder_traversal(root);
    cout<<"\n\nIn-Order Tree Traversal\n";
    inorder_traversal(root);
    cout<<"\n\n\n";
    return 0;
}
