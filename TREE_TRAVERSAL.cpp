#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//  Given a Binary Search Tree
//   Perform following tree traversal
//   1- Level Order Traversal (Breadth First Search)
//   2- Preorder Traversal    (Depth First Search)
//   3- Inorder Traversal     (Depth First Search)
//   4- Postorder Traversal   (Depth First Search)
//
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
//
//   Now let's apply different tree traversal
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

void preorder_traversal(bst *root)
{
    if(root==NULL) return;  // base condition
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void inorder_traversal(bst *root)
{
    if(root==NULL) return;  // base condition
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
void postorder_traversal(bst *root)
{
    if(root==NULL) return;  // base condition
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
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
    nodes=7;
    vector <ll> nodes_of_tree(nodes);
    nodes_of_tree[0]=20;
    nodes_of_tree[1]=10;
    nodes_of_tree[2]=30;
    nodes_of_tree[3]=2;
    nodes_of_tree[4]=15;
    nodes_of_tree[5]=25;
    nodes_of_tree[6]=45;
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
    cout<<"\n";
    cout<<"\nPRE-ORDER TRAVERSAL (Breadth first search)\n";
    preorder_traversal(root);
    cout<<"\n\nIN-ORDER TRAVERSAL (Breadth first search)\n";
    inorder_traversal(root);
    cout<<"\n\nPOST-ORDER TRAVERSAL (Breadth first search)\n";
    postorder_traversal(root);
    cout<<"\n\n";
    return 0;
}
