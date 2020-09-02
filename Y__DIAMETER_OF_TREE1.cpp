#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//    You are given a Binary TREE (may be BST)
//    You have to determine it's Diameter in O(nodes) complexity
//
//    The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
//    Consider the below given BST
//
//           root ->100
//                  /  \
//                 /    \
//                3     120
//               / \
//              /   \
//             2     \
//                    50
//                   /  \
//                 49    60
//                /        \
//              30          70
//             /  \        /  \
//           20    35     65   80
//          /                    \
//        10                      90
//       /  \
//      5    16
//     /       \
//    4         17
//                \
//                 18
//
//    The diameter of above given BST is 12
//    The nodes involved in diameter are {18,17,16,10,20,30,49,50,60,70,80,90}
//
//
class Node_Of_Tree
{
public:
    ll data;
    Node_Of_Tree *left;     // pointers left child
    Node_Of_Tree *right;    // pointer right child
    Node_Of_Tree()  // constructor  (just use it for good practice)
    {
        data=0;
        left=NULL;
        right=NULL;
    }
};
typedef Node_Of_Tree bst;
// bst stands for -> Binary Search TREE

void insert_in_bst(bst *root,bst *temp)
{
    if(root->data > temp->data)  // left insertion case
    {
        if(root->left==NULL)  // check if space available
        {
            root->left=temp;   // insert it and return
            return;
        }
        else
        {
            insert_in_bst(root->left,temp);  // recursion call
        }
    }
    else // right insertion case
    {
        if(root->right==NULL)  // check if space available
        {
            root->right=temp;  // insert it and return
            return;
        }
        else
        {
            insert_in_bst(root->right,temp);    // recursion call
        }
    }
}

void preorder_traversal(bst *root)
{
    if(root==NULL) return; // base condition
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(bst *root)
{
    if(root==NULL) return; // base condition
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
//***********************************************************************
ll diameter_of_tree(bst *root,ll &dia)
{
    if(root==NULL) return 0; // base condition
    ll a=diameter_of_tree(root->left,dia);
    ll b=diameter_of_tree(root->right,dia);
    dia=max(dia,(a+b+1));
    return (1+max(a,b));
}
//***********************************************************************
int main()
{
    ios_base::sync_with_stdio(false);
    bst* root=NULL;  // pointer that will point the root node
    ll nodes=17;
    //cin>>nodes;
    vector <ll> node_values;
    node_values.push_back(100);     node_values.push_back(3);
    node_values.push_back(2);       node_values.push_back(120);
    node_values.push_back(50);      node_values.push_back(60);
    node_values.push_back(70);      node_values.push_back(80);
    node_values.push_back(90);      node_values.push_back(65);
    node_values.push_back(49);      node_values.push_back(30);
    node_values.push_back(35);      node_values.push_back(20);
    node_values.push_back(10);      node_values.push_back(5);
    node_values.push_back(4);

    for(int i=0;i<nodes;i++)
    {
        bst *temp = new (bst);
        temp->data=node_values[i];
        if(root==NULL)  // first  node to be added
        {
            root=temp;continue;
        }
        insert_in_bst(root,temp);
    }
    cout<<"\n  Pre order Traversal\n  ";
    preorder_traversal(root);
    cout<<"\n\n  Inorder Traversal\n  ";
    inorder_traversal(root);
    ll dia=-1;
    ll height=diameter_of_tree(root,dia);
    cout<<"\n\n Diameter of Tree = "<<dia<<"\n";
    cout<<"\n Height of Tree = "<<height<<"  (if leaf node has height 1)\n";
    cout<<"\n Height of Tree = "<<height-1<<"  (if leaf node has height 0)\n";

    return 0;
}

