#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//    Given a Binary Search Tree (BST)
//    You have check if a element is present or not in BST
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
//      Search 50
//      Yes, 50 is present in BST
//      Search 130
//      Yes, 130 is present in BST
//      Search 135
//      No, 135 is not present in BST
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
bool search_in_bst(bst *root,ll &element)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==element)
    {
        return true;
    }
    if(root->data > element)
    {
        search_in_bst(root->left,element);
    }
    else
    {
        search_in_bst(root->right,element);
    }
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
    cout<<"\n";
    //**************************************************************************************
    ll element;
    element=50;
    cout<<"\nSearch for 50\n";
    bool check=search_in_bst(root,element);

    (check==true)?cout<<"\nYes, "<<element<<" is present in BST\n":cout<<"\nNo, "<<element<<" is not present in BST\n";

    //**************************************************************************************
    element=130;
    cout<<"\nSearch for 130\n";
    check=search_in_bst(root,element);

    (check==true)?cout<<"\nYes, "<<element<<" is present in BST\n":cout<<"\nNo, "<<element<<" is not present in BST\n";

    //**************************************************************************************

    element=135;
    cout<<"\nSearch for 135\n";
    check=search_in_bst(root,element);

    (check==true)?cout<<"\nYes, "<<element<<" is present in BST\n":cout<<"\nNo, "<<element<<" is not present in BST\n";

    //**************************************************************************************

    element=70;
    cout<<"\nSearch for 70\n";
    check=search_in_bst(root,element);

    (check==true)?cout<<"\nYes, "<<element<<" is present in BST\n":cout<<"\nNo, "<<element<<" is not present in BST\n";
    return 0;
}
