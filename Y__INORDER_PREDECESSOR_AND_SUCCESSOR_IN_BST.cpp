#include <bits/stdc++.h>
#define in input_nodes   // use it for efficiency
#define pb push_back    // use this macro for saving time and efficiency
using namespace std;
typedef long long ll;
//    You are given a Binary Search Tree with all unique nodes
//    Then you will be provided with any random node data
//
//    You have to determine the following for that random node
//    1. In-Order predecessor node if it exist  (search on Google for definition)
//    2. In-Order successor   node if it exist  (search on Google for definition)
//
//    Steps involved
//    We will discuss any one of them here:
//    Let's discuss the procedure to find in-order successor of a node
//
//    step 1 - Find that node in given BST
//    step 2 -
//             a.  if there exist a right child of given node then
//                 find the smallest node in this right sub tree
//
//              else
//
//             b.  if there exist no right child of given node then
//                  traverse tree back from root to node, and maintain this order
//                      ll in_order_successor=-1;
//                      while(root!=NULL)
//                      {
//                          if(root->data == node) break;
//                          if(root->data > node)
//                          {
//                              in_order_successor=root->data;
//                              root=root->left;
//                          }
//                          else
//                          {
//                               root=root->right;
//                          }
//                       }
//                       return in_order_successor;
//
//
//
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
//
//    Node = 100
//    In-order predecessor  of 100 is = 75
//    In-order successor    of 100 is = 110
//
//    Node = 115
//    In-order predecessor  of 115 is = 110
//    In-order successor    of 115 is = 125
//
//
//
class Node_Of_Binary_Tree
{
public:
    ll data;
    Node_Of_Binary_Tree *left;  // left pointer
    Node_Of_Binary_Tree *right; // right pointer
    Node_Of_Binary_Tree()  //constructor
    {
        data=0;
        left=right=NULL;
    }
};
typedef Node_Of_Binary_Tree bst;
// bst stands for Binary Search Tree
void insert_into_bst(bst *,bst*);
void preorder_traversal(bst *);
void inorder_traversal(bst *);

//*******************************************************************************************************
// this function is used to search any given node in BST
// If it is found then it written the address of node and true
// If it is not found then it written NULL and false
bst* search_in_bst(bst *root,ll node,bool &f)
{
    if(root==NULL) {f=false;  return root;}
    if(root->data==node) {f=true; return root;}
    if(root->data > node)
    {
        bst* curr=search_in_bst(root->left,node,f);
        return curr;
    }
    else
    {
        bst* curr=search_in_bst(root->right,node,f);
        return curr;
    }
}
//*******************************************************************************************************

//   Below are the three functions which are use to find in-order predecessor of any node

// this function is used when we are finding in-order predecessor of a node, and there exist a left child of that node
ll find_minimum_node_in_left_sub_tree(bst *root)
{
    ll mini=-1;
    while(root!=NULL)
    {
        mini=root->data;
        root=root->right;
    }
    return mini;
}
// this function is used when we are finding in-order predecessor of a node, and there exist no left child of that node
ll find_inorder_predecessor_node_in_tree(bst *root,ll node)
{
    ll in_order_predecessor=-1;
    while(root!=NULL)
    {
        if(root->data == node) break;
        if(root->data < node)
        {
            in_order_predecessor=root->data;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return in_order_predecessor;
}
// this is the driver function to find in-order predecessor of any node
ll find_inorder_predecessor(bst *root,ll node)
{
    bool f=false;
    bst* curr=search_in_bst(root,node,f);
    if(f==false)
    {
        cout<<node<<" is not present in BST\n";
        return -1;
    }
    if(curr->left!=NULL)  // if left child exist for given node, we will find the smallest node in it's left sub tree
    {
        ll inorder_predecessor=find_minimum_node_in_left_sub_tree(curr->left);
        return inorder_predecessor;
    }
    else  // left child does not exist, we will traverse tree and then compute it
    {
        ll inorder_predecessor=find_inorder_predecessor_node_in_tree(root,node);
        return inorder_predecessor;
    }
}
//*******************************************************************************************************

//   Below are the three functions which are use to find in-order successor of any node

// this function is used when we are finding in-order successor of a node, and there exist a right child of that node
ll find_minimum_node_in_right_sub_tree(bst *root)
{
    ll mini=-1;
    while(root!=NULL)
    {
        mini=root->data;
        root=root->left;
    }
    return mini;
}

// this function is used when we are finding in-order successor of a node, and there exist no right child of that node
ll find_inorder_successor_node_in_tree(bst *root,ll node)
{
    ll in_order_successor=-1;
    while(root!=NULL)
    {
        if(root->data == node) break;
        if(root->data > node)
        {
            in_order_successor=root->data;
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return in_order_successor;
}

// this is the driver function to find in-order successor of any node
ll find_inorder_successor(bst *root,ll node)
{
    bool f=false;
    bst* curr=search_in_bst(root,node,f);
    if(f==false)
    {
        cout<<node<<" is not present in BST\n";
        return -1;
    }
    if(curr->right!=NULL)  // if right child exist for given node, we will find the smallest node in it's right sub tree
    {
        ll inorder_successor=find_minimum_node_in_right_sub_tree(curr->right);
        return inorder_successor;
    }
    else  // right child does not exist, we will traverse tree and then compute it
    {
        ll inorder_successor=find_inorder_successor_node_in_tree(root,node);
        return inorder_successor;
    }
}

//*******************************************************************************************************


void solve(bst *root,ll node)
{
    cout<<"\nInput node = "<<node<<"\n";
    ll in_ord_pre = find_inorder_predecessor(root,node);
    (in_ord_pre==-1) ?cout<<node<<"'s in-order predecessor does not exist\n" :cout<<node<<"'s in-order predecessor = "<<in_ord_pre<<"\n" ;

    ll in_ord_suc = find_inorder_successor(root,node);
    (in_ord_suc==-1) ?cout<<node<<"'s in-order successor does not exist\n" :cout<<node<<"'s in-order successor = "<<in_ord_suc<<"\n" ;
}

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

    cout<<"PRE-ORDER TREE TRAVERSAL\n";
    preorder_traversal(root);cout<<"\n\n";
    cout<<"IN-ORDER TREE TRAVERSAL\n";
    inorder_traversal(root);cout<<"\n\n";

    ll node;

    node=115;
    solve(root,node);

    node=5;
    solve(root,node);

    node=300;
    solve(root,node);

    node=100;
    solve(root,node);

    node=7;
    solve(root,node);

    return 0;
}


//  this function is used to insert nodes in BST
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
// Tree traversal functions
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
