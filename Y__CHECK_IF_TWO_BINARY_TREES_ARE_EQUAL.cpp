#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//    Given two Binary Trees
//    You have to determine if they are equal or not
//    Brute force solution is that find any order traversal of both the trees and then compare
//
//    But
//    We will use more efficient method
//    The idea is that, we will simultaneously perform Level Order Traversal in both trees and compare nodes every time
//    The moment we get our first unmatched, we will stop further comparison
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
//                       10              20                |                    10              20
//                      /  \            /  \               |                   /  \             / \
//                     /    \          /    \              |                  /    \           /   \
//                    /      \        /      \             |                 /      \         /     \
//                   5       11      15      22            |                /        \       /       \
//                  / \             /  \       \           |               5         11     15       22
//                 /   \           /    \       \          |              / \              /  \        \
//                3     7         13    18      30         |             /   \            /    \        \
//                     /               /  \                |            3     7          13    18        30
//                    /               /    \               |                                  / \
//                   6               17    19              |                                 /   \
//                                                         |                                17   19
//
//       The above two trees are equal
//

class Node_Of_Tree
{
public:
    ll data;
    Node_Of_Tree *left=NULL;
    Node_Of_Tree *right=NULL;
};
typedef Node_Of_Tree bst;

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
void inorder_traversal(bst *root)
{
    if(root==NULL) return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
//******************************************************************************************************
bool check_if_tree_are_equal(bst *root1,bst *root2)
{
    queue <bst*> q1;
    queue <bst*> q2;
    if(root1!=NULL) q1.push(root1);
    if(root2!=NULL) q2.push(root2);
    while(!q1.empty()  && !q2.empty())
    {
        if(q1.size()!=q2.size()) return false;
        bst *temp1=q1.front();
        bst *temp2=q2.front();
        if(temp1->data!=temp2->data) return false;
        q1.pop();q2.pop();
        if(temp1->left!=NULL) q1.push(temp1->left);
        if(temp1->right!=NULL) q1.push(temp1->right);
        if(temp2->left!=NULL) q2.push(temp2->left);
        if(temp2->right!=NULL) q2.push(temp2->right);
    }
    if(!q1.empty() || !q2.empty() ) return false;
    return true;
}
//******************************************************************************************************
int main()
{
    ios_base::sync_with_stdio(false);
    bst *root1=NULL;    // pointer that will point the root node
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
        if(root1==NULL)
        {
            root1=temp;continue;
        }
        input_in_bst(root1,temp);
    }
    cout<<"     TREE 1";
    cout<<"\n PRE-ORDER TRAVERSAL\n ";
    preorder_traversal(root1);
    cout<<"\n IN-ORDER TRAVERSAL\n ";
    inorder_traversal(root1);


    bst *root2=NULL;    // pointer that will point the root node
    nodes=15;
    input_nodes.clear();
    in.pb(12);     in.pb(20);     in.pb(10);     in.pb(11);
    in.pb(5);     in.pb(22);     in.pb(15);     in.pb(30);
    in.pb(18);      in.pb(13);     in.pb(7);     in.pb(3);
    in.pb(6);      in.pb(19);     in.pb(17);
    for(int i=0;i<nodes;i++)
    {
        bst *temp=new(bst);
        temp->data=in[i];
        if(root2==NULL)
        {
            root2=temp;continue;
        }
        input_in_bst(root2,temp);
    }
    cout<<"\n\n     TREE 2";
    cout<<"\n PRE-ORDER TRAVERSAL\n ";
    preorder_traversal(root2);
    cout<<"\n IN-ORDER TRAVERSAL\n ";
    inorder_traversal(root2);
    bool check=check_if_tree_are_equal(root1,root2);
    if(check==false)
    {
        cout<<"\n\nTrees are not equal\n";
    }
    else
    {
        cout<<"\n\nTrees are equal\n";
    }
    return 0;
}

