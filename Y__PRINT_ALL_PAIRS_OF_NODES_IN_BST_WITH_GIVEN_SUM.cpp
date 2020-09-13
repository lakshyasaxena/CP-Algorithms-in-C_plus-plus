#include <bits/stdc++.h>
#define pb push_back
#define in input_nodes
using namespace std;
typedef long long ll;
//
//       Given a Binary Search Tree (BST) with all unique nodes
//       And then you will be given a sum
//       You have to print all possible pairs of nodes whose summation is equal to sum
//
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
//        Example:
//        Sum = 26
//        (2,24)
//        (3,23)
//        (5,21)
//        (6,20)
//        (9,17)
//        (11,15)
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
bool search_in_bst(bst *root,ll data)
{
    if(root==NULL) { return false; }             // base condition 1 ( data not found )
    if(root->data == data){return true;}         // base condition 2 ( data found     )
    if(root->data > data)                        // search in left sub tree
    {
        bool f=search_in_bst(root->left,data);
        return f;
    }
    else                                         // search in right sub tree
    {
        bool f=search_in_bst(root->right,data);
        return f;
    }
}

void in_order_traverse(bst *root,bst *fixed_root,ll &sum,vector <pair <ll , ll > > &pair_of_nodes)
{
    if(root==NULL  ) return ;                                      //  base condition
    in_order_traverse(root->left,fixed_root,sum,pair_of_nodes);    //  first go to left
    if(root->data > (sum/2)) return;                              //  this base condition is to avoid the repetition storage in vector of pair

    //cout<<root->data<<",";                                       //  then visit
    ll diff=sum-root->data;
    bool f=search_in_bst(fixed_root,diff);                         //  search in BST

    if(f && diff!=root->data)  pair_of_nodes.push_back(make_pair(root->data,diff));    // if (f==true), then push pair in vector

    in_order_traverse(root->right,fixed_root,sum,pair_of_nodes);     //  then go to right
}
void find_pair_sum_from_bst(bst *root,ll sum,vector <pair <ll,ll > > &pair_of_nodes)
{
    while(root->data >= sum)
    {
        root=root->left;
    }
    in_order_traverse(root,root,sum,pair_of_nodes);
}
//**************************************************************************************************************************************************
void traverse_pairs(vector <pair <ll , ll > > &v1)
{
    for(int i=0;i<v1.size();i++)
    {
        cout<<"("<<v1[i].first<<" "<<v1[i].second<<")\n";
    }
}
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

    ll sum;
    vector <pair <ll,ll > > pair_of_nodes;

    sum=26;
    cout<<"Given sum = "<<sum<<"\n";

    find_pair_sum_from_bst(root,sum,pair_of_nodes);
    traverse_pairs(pair_of_nodes);
    pair_of_nodes.clear();


    sum=11;
    cout<<"Given sum = "<<sum<<"\n";

    find_pair_sum_from_bst(root,sum,pair_of_nodes);
    traverse_pairs(pair_of_nodes);
    pair_of_nodes.clear();

    sum=47;
    cout<<"Given sum = "<<sum<<"\n";

    find_pair_sum_from_bst(root,sum,pair_of_nodes);
    traverse_pairs(pair_of_nodes);
    pair_of_nodes.clear();

    sum=30;
    cout<<"Given sum = "<<sum<<"\n";

    find_pair_sum_from_bst(root,sum,pair_of_nodes);
    traverse_pairs(pair_of_nodes);
    pair_of_nodes.clear();

    sum=3;
    cout<<"Given sum = "<<sum<<"\n";

    find_pair_sum_from_bst(root,sum,pair_of_nodes);
    traverse_pairs(pair_of_nodes);
    pair_of_nodes.clear();
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
