#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//    Problem Statement : You are given a Binary Tree. You have to find and print the largest Binary search tree in it.
//
//    For reference consider the below given Binary tree
//
//                                  BT
//                              root-> 25
//                                    /  \
//                                  _/    \_
//                                _/        \_
//                              _/            \_
//                            _/                \_
//                           /                    \
//                          /                      \                               Largest BST
//                         18                      50                             Bst root-> 50
//                        / \                      / \                                      /  \
//                      _/   \_                  _/   \_                                   /    \
//                     /       \                /       \       ---->>                    /      \
//                    /         \              /         \                               /        \
//                   19         20            35         60                             35        60
//                    \        /  \          /  \       /  \                           /  \      /  \
//                    15      18  25        20  40     55  70                         20  40    55  70
//                                         /                                         /
//                                        17                                        17
//
//    In the above BT, the largest BST size is 8
//    In-Order of largest bst  -> 17 , 20 , 35 , 40 , 50 , 55 , 60 , 70
//    Pre-Order of largest bst -> 50 , 35 , 20 , 17 , 40 , 60 , 55 , 70
//
//   Time complexity  O(n)
//   Where n is the number of nodes
//   Approach
//   We will use bottom up manner technique to solve this problem (Post order traversal of binary tree)
//   1- We will recursively call the left and then right sub tree until we met base conditions
//   2- We can encounter two base condition
//      a- Either a node is the leaf node ( We will consider it as smallest BST )
//      b- A node has only one child
//
//   3- Then we will receive data from left Sub Tree and right Sub Tree and check following conditions
//
//       a- If
//            Present_root->data is greater than maximum value of left sub tree
//                                        AND
//            Present_root->data is smaller than minimum value of right sub tree
//                                    then it means
//            We can include the present root in a BST and return the updated data
//
//       b- Else
//            We will return the data of maximum size of BST from (left sub tree & right sub tree )
//
//   Comments can fool you, believe in code
//
class Binary_Tree_Node
{
public:
    ll data;
    Binary_Tree_Node *left=NULL;
    Binary_Tree_Node *right=NULL;
};
typedef Binary_Tree_Node bt;

bt* insert_into_binary_tree(bt *);  // This function is just used to insert nodes in the Binary Tree


class my_structure_to_be_return
{
public:
    bool is_tree=false;
    ll min_value=0;
    ll max_value=0;
    ll max_size=0;
    bt *ptr=NULL;
};
typedef my_structure_to_be_return ret;


//****************************************************************************************************************************************************
ret* find_largest_bst_in_bt(bt *root)
{
    if(root==NULL)  // case of single child
    {
        ret*temp=new(ret);
        temp->is_tree=true;
        temp->min_value=INT_MAX;  // in minimum, we provide +infinity
        temp->max_value=INT_MIN;  // in maximum, we provide -infinity
        temp->max_size=0;
        temp->ptr=NULL;
        return {temp};
    }
    if(root->left==NULL && root->right==NULL)  // case of leaf node
    {
        ret*temp=new(ret);
        temp->is_tree=true;
        temp->min_value=root->data;
        temp->max_value=root->data;
        temp->max_size=1;
        temp->ptr=root;
        return {temp};
    }

    ret *left_ret=new(ret);
    left_ret=find_largest_bst_in_bt(root->left);

    ret *right_ret=new(ret);
    right_ret=find_largest_bst_in_bt(root->right);

    ret *ret_result=new(ret);

    if(left_ret->is_tree==true && right_ret->is_tree==true  && left_ret->max_value < root->data && right_ret->min_value > root->data)  // Bst property continued
    {
        ret_result->is_tree=true;
        ret_result->min_value=min( left_ret->min_value, min( root->data , right_ret->min_value ) );
        ret_result->max_value=max( right_ret->max_value, max( root->data , left_ret->max_value) );
        ret_result->max_size=(1 + left_ret->max_size + right_ret->max_size);
        ret_result->ptr=root;
        delete(left_ret);
        delete(right_ret);
        return ret_result;
    }
    else
    {
        ret_result->is_tree=false;
        ret_result->min_value=0;  // does not matter what ever value you provide
        ret_result->max_value=0;  // does not matter what ever value you provide
        if(left_ret->max_size >= right_ret->max_size)
        {
            ret_result->max_size=left_ret->max_size;
            ret_result->ptr=left_ret->ptr;
        }
        else
        {
            ret_result->max_size=right_ret->max_size;
            ret_result->ptr=right_ret->ptr;
        }
        delete(left_ret);
        delete(right_ret);
        return ret_result;
    }
}
//****************************************************************************************************************************************************


void inorder_traversal(bt *root)
{
    if(root==NULL) return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

void preorder_traversal(bt *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main()
{
    bt *root=NULL; // root pointer
    root=insert_into_binary_tree(root);
    cout<<"Pre-Order of Binary Tree\n";
    preorder_traversal(root);cout<<"\n";
    cout<<"In-Order of Binary Tree\n";
    inorder_traversal(root);
    cout<<"\n\n";
    ret *temp=find_largest_bst_in_bt(root);

    ll size_of_largest_bst=temp->max_size;
    bt* root_of_binary_search_tree=temp->ptr;

    cout<<"\n\nSize of Largest BST is "<<size_of_largest_bst;

    cout<<"\n\nIN-ORDER TRAVERSAL OF LARGEST BST\n";
    inorder_traversal(root_of_binary_search_tree);

    cout<<"\n\nPRE-ORDER TRAVERSAL OF LARGEST BST\n";
    preorder_traversal(root_of_binary_search_tree);

    cout<<"\n\n\n";
    return 0;
}

// This below function has nothing to do with actual logic, it is just used to build Binary Tree

bt* insert_into_binary_tree(bt *root)
{
    bt *temp=new(bt);
    temp->data=25;
    root=temp;
    temp=new(bt);
    temp->data=18;
    root->left=temp;
    temp=new(bt);
    temp->data=50;
    root->right=temp;
    temp=new(bt);
    temp->data=19;
    root->left->left=temp;
    temp=new(bt);
    temp->data=20;
    root->left->right=temp;
    temp=new(bt);
    temp->data=35;
    root->right->left=temp;
    temp=new(bt);
    temp->data=60;
    root->right->right=temp;
    temp=new(bt);
    temp->data=15;
    root->left->left->right=temp;
    temp=new(bt);
    temp->data=18;
    root->left->right->left=temp;
    temp=new(bt);
    temp->data=25;
    root->left->right->right=temp;
    temp=new(bt);
    temp->data=20;
    root->right->left->left=temp;
    temp=new(bt);
    temp->data=40;
    root->right->left->right=temp;
    temp=new(bt);
    temp->data=55;
    root->right->right->left=temp;
    temp=new(bt);
    temp->data=70;
    root->right->right->right=temp;
    temp=new(bt);
    temp->data=17;
    root->right->left->left->left=temp;
    return root;
}
