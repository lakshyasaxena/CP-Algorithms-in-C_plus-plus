#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//  Given a Binary Search Tree
//   Find following details in tree
//   1- Level Order Traversal (Breadth First Search)
//   2- Count of leaf nodes
//   3- Count of internal nodes
//   4- Height of tree
//   5- Levels in tree
//  Consider the following Binary Search Tree
//
//                    20
//                   /  \
//                  /    \
//                 /      \
//                /        \
//               /          \
//              10           30
//             / \           /\
//            /   \         /  \
//           /     \       /    \
//          2      15     25    45
//         /                      \
//        /                        \
//       /                          \
//      1                           49
//
//   Now let's find the required information
//
class Node_Of_Binary_Search_Tree
{
public:
    ll data;  // the node index
    Node_Of_Binary_Search_Tree *left,*right;   // pointers that will hold address of children node
    Node_Of_Binary_Search_Tree()  // constructor
    {
        left=NULL;
        right=NULL;
        data=0;
    }
};
typedef Node_Of_Binary_Search_Tree bst;

void level_traversal(bst *root)
{
    queue <bst*> q1;
    q1.push(root);
    while(!q1.empty())
    {
        bst *current=q1.front();
        q1.pop();
        cout<<current->data<<" ";
        if(current->left!=NULL) q1.push(current->left);
        if(current->right!=NULL) q1.push(current->right);
    }
}
ll count_leaf_nodes(bst *root)
{
    if(root==NULL) return 0; // base condition 1 (case of one children)
    if(root->left==NULL && root->right==NULL) { return 1; }  // base condition 2  (case of no children)
    ll a=count_leaf_nodes(root->left);
    ll b=count_leaf_nodes(root->right);
    return (a+b);
}
ll count_internal_nodes(bst *root)
{
    if(root==NULL) return 0; // base condition 1 (case of one children)
    if(root->left==NULL && root->right==NULL) { return 0; }  // base condition 2  (case of no children)
    ll a=count_internal_nodes(root->left);
    ll b=count_internal_nodes(root->right);
    return (a+b+1);
}
ll find_height(bst *root)
{
    if(root==NULL) return 0; // base condition
    if(root->left==NULL && root->right==NULL) { return 1; } // base condition 2 (condition of no child )
    ll a=find_height(root->left);
    ll b=find_height(root->right);
    return (1+max(a,b));
}
void insert_node_in_bst(bst *current,bst *temp)
{
    if(current->data > temp->data)  // left insertion
    {
        if(current->left==NULL)
        {
            current->left=temp; return;
        }
        insert_node_in_bst(current->left,temp);
    }
    else
    {
        if(current->right==NULL)
        {
            current->right=temp; return;
        }
        insert_node_in_bst(current->right,temp);
    }
}
int main()
{
    bst *root=NULL;  // root pointer, will point root node in our BST
    ll nodes;
    //cin>>nodes;
    nodes=9;
    vector <ll> nodes_of_tree(nodes);
    nodes_of_tree[0]=20;
    nodes_of_tree[1]=10;
    nodes_of_tree[2]=30;
    nodes_of_tree[3]=2;
    nodes_of_tree[4]=15;
    nodes_of_tree[5]=25;
    nodes_of_tree[6]=45;
    nodes_of_tree[7]=1;
    nodes_of_tree[8]=49;
    for(int i=0;i<nodes;i++)
    {
        bst *temp=new (bst); // create new object, whose reference is given to temp pointer
        temp->data=nodes_of_tree[i];  // value stored at data
        if(root==NULL) // first node is inserted
        {
            root=temp;
            continue;
        }
        insert_node_in_bst(root,temp);
    }
    cout<<"\nLevel Wise Tree TRAVERSAL (Breadth first search)\n";
    level_traversal(root);
    ll leaf_nodes=count_leaf_nodes(root);
    cout<<"\n\nThere are "<<leaf_nodes<<" leaf nodes\n";
    ll internal_nodes=count_internal_nodes(root);
    cout<<"\nThere are "<<internal_nodes<<" internal nodes\n";
    ll height=find_height(root);
    cout<<"\n\nHeight of TREE is = "<<height<<" (if you consider height of leaf node as 1)\n";
    cout<<"AND\n";
    cout<<"Height of TREE is = "<<(height-1)<<" (if you consider height of leaf node as 0)\n";
    cout<<"\nThere are "<<height<<" Levels in tree\n\n\n";
    return 0;
}
