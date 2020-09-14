#include <bits/stdc++.h>
#define pb push_back
#define in input_nodes
using namespace std;
typedef long long ll;
//
//       Given a Binary TREE (may be BST)
//       You have to find two things
//       1. Top     view of Binary Tree
//       2. Bottom  view of Binary Tree
//       Note: The order is not important, you may print them in any order
//       For reference consider this BST
//
//                                              root -> 12
//                                                    _/  \_
//                                                  _/      \_
//                                                _/          \_
//                                              _/              \_
//                                            _/                  \_
//                                          _/                      \_
//                                         /                          \
//                                        10                           20
//                                      _/ \_                        _/  \_
//                                    _/     \_                    _/      \_
//                                   /         \                  /          \
//                                  5           11               17           24
//                                _/ \_                         /  \         /  \
//                               /     \                       /    \       /    \
//                              3       7                     15    18     23    30
//                             /       / \                                /      / \
//                            /       /   \                              /      /   \
//                           1       6     9                            21     26   34
//                            \
//                             2
//
//
//    Top    View ->  12  10  20  5  24  3  30  1  34
//
//    Bottom View ->  1  2  6  15  21  23  26  30  34
//
//
class Binary_Search_Tree_Node  // Structure of each Node of BST
{
public:
    ll data;
    Binary_Search_Tree_Node *left=NULL;
    Binary_Search_Tree_Node *right=NULL;
};
typedef Binary_Search_Tree_Node bst;

bst* insert_in_bst(bst* ,bst* );
void preorder_tree_traversal(bst *);
void inorder_tree_traversal(bst *);

//**************************************************************************************************************************************************
void top_view_binary_tree(bst *root)
{
    cout<<"Top View of Binary Tree\n";
    map <ll,ll> m;
    queue <pair <bst* ,ll > > q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        root=q.front().first;
        ll horizontal_value=q.front().second;
        q.pop();

        map<ll,ll>::iterator itr=m.find(horizontal_value);
        if(itr==m.end())  // absent in map, it's a new value, must be visible from top
        {
            cout<<root->data<<" ";   // visit this node
            m[horizontal_value]++;   // make it visible in map
        }
        else             // already present in map, it may not be visible from top
        {
            // do nothing
        }

        if(root->left!=NULL)    q.push(make_pair(root->left,(horizontal_value-1)));
        if(root->right!=NULL)   q.push(make_pair(root->right,(horizontal_value+1)));
    }
    cout<<"\n\n\n";
}
void bottom_view_binary_tree(bst *root)
{
    cout<<"Bottom View of Binary Tree\n";
    map <ll,ll> m;
    queue <pair <bst*, ll > > q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        root=q.front().first;
        ll horizontal_value=q.front().second;
        q.pop();

        m[horizontal_value]=root->data;      // keep updating the map with latest horizontal value

        if(root->left!=NULL)    q.push(make_pair(root->left,(horizontal_value-1)));
        if(root->right!=NULL)   q.push(make_pair(root->right,(horizontal_value+1)));
    }

    for(map<ll,ll>::iterator itr=m.begin(); itr!=m.end(); itr++)
    {
        cout<<itr->second<<" ";
    }
    cout<<"\n\n\n";
}
//**************************************************************************************************************************************************
int main()
{
    bst *root=NULL;  // root pointer, that will point to root node
    ll nodes=20;
    vector <ll> input_nodes;  // we have used { in } as macro for input_nodes and pb stands for push_back
    in.pb(12);    in.pb(10);    in.pb(20);    in.pb(5);    in.pb(11);    in.pb(17);    in.pb(24);    in.pb(3);     in.pb(7);    in.pb(15);
    in.pb(18);    in.pb(23);    in.pb(30);    in.pb(1);    in.pb(6);     in.pb(9);     in.pb(21);    in.pb(26);    in.pb(34);   in.pb(2);
    for(int i=0;i<nodes;i++)
    {
        bst* temp=new(bst);
        temp->data=in[i];
        root=insert_in_bst(root,temp);
    }
    cout<<"Pre-Order Tree Traversal\n";
    preorder_tree_traversal(root);
    cout<<"\n\n";
    cout<<"IN-Order Tree Traversal\n";
    inorder_tree_traversal(root);
    cout<<"\n\n";

    top_view_binary_tree(root);

    bottom_view_binary_tree(root);

    return 0;
}


// this function is used to insert nodes in BST
bst* insert_in_bst(bst *root,bst *temp)
{
    if(root==NULL)
    {
        root=temp;return root;
    }
    if(root->data > temp->data)     // case of left child
    {
        if(root->left==NULL)
        {
            root->left=temp; return root;
        }
        root->left=insert_in_bst(root->left,temp);
    }
    else
    {
        if(root->right==NULL)     // case of right child
        {
            root->right=temp; return root;
        }
        root->right=insert_in_bst(root->right,temp);
    }
    return root;
}
void preorder_tree_traversal(bst *root)
{
    if(root==NULL) return ;                 // base condition
    cout<<root->data<<" ";                  // first visit
    preorder_tree_traversal(root->left);    // then go to left
    preorder_tree_traversal(root->right);   // then go to right
}
void inorder_tree_traversal(bst *root)
{
    if(root==NULL) return ;                // base condition
    inorder_tree_traversal(root->left);    //first go to left
    cout<<root->data<<" ";                 // then visit
    inorder_tree_traversal(root->right);   // then go to right
}
