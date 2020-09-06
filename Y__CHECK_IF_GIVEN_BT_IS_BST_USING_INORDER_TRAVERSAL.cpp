#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//    Given a Binary Tree
//    You have to determine whether it's a Binary Search Tree or not using In-Order Tree Traversal
//
//    For reference, consider the two Binary Tree given below
//
//    In this we would use In-order Tree Traversal to check for Binary search Tree
//    The idea is very simple, we will perform in-order tree traversal and store previous data at each step
//    We will compare previous data with current data at each step and if at any point any violation occurs
//    We will stop further computation and return with false condition
//    Other wise we will return with true condition
//
//
//                      Tree 1                          //                      Tree 2
//                                                      //
//                     root-> 50                        //                     root-> 50
//                           /  \                       //                           /  \
//                          /    \                      //                          /    \
//                         /      \                     //                         /      \
//                        /        \                    //                        /        \
//                       /          \                   //                       /          \
//                      /            \                  //                      /            \
//                     /              \                 //                     /              \
//                    30              60                //                    30              60
//                   /  \             / \               //                   /  \             / \
//                  /    \           /   \              //                  /    \           /   \
//                 /      \         /     \             //                 /      \         /     \
//                /        \       /       \            //                /        \       /       \
//               10        40     55        80          //               10        40     55        80
//              /          / \             / \          //              /          / \             / \
//             /          /   \           /   \         //             /          /   \           /   \
//            /          /     \         /     \        //            /          /     \         /     \
//           1          35     45       70     100      //           1          35      4       70     100
//                     /  \              \              //                     /  \              \
//                    33  37             75             //                    33  37             75
//
//
//   Binary Tree 1 is a Binary Search Tree
//
//   Binary Tree 2 is not a Binary search Tree
//
class Binary_Search_Tree_Node
{
public:
    ll data;
    Binary_Search_Tree_Node *left=NULL;
    Binary_Search_Tree_Node *right=NULL;
};
typedef Binary_Search_Tree_Node bst;

bst* insert_in_tree(bst *);
bst* insert_in_tree2(bst *);

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
void check_if_binary_search_tree(bst *root,ll &previous,bool &check)
{
    if(root==NULL || check==false) return;
    check_if_binary_search_tree(root->left,previous,check);

    if(check==false) return;

    if(root->data < previous)
    {
        check=false;
        return;
    }
    previous=root->data;

    check_if_binary_search_tree(root->right,previous,check);


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
    root=insert_in_tree(root);
    cout<<"Tree 1\n";
    cout<<"Pre-Order Tree traversal\n";
    preorder_traversal(root);
    cout<<"\n\nIn-Order Tree traversal\n";
    inorder_traversal(root);
    bool check=true;
    ll previous=INT_MIN;
    check_if_binary_search_tree(root,previous,check);
    if(check==false)
    {
        cout<<"\n\nThe Tree is not a Binary Search Tree\n";
    }
    else
    {
        cout<<"\n\nThe Tree is a Binary Search Tree\n";
    }


    bst *root2=NULL;
    root2=insert_in_tree2(root2);
    cout<<"\nTree 2\n";
    cout<<"Pre-Order Tree traversal\n";
    preorder_traversal(root2);
    cout<<"\n\nIn-Order Tree traversal\n";
    inorder_traversal(root2);
    check=true;
    previous=INT_MIN;
    check_if_binary_search_tree(root2,previous,check);
    if(check==false)
    {
        cout<<"\n\nThe Tree is not a Binary Search Tree\n";
    }
    else
    {
        cout<<"\n\nThe Tree is a Binary Search Tree\n";
    }

    return 0;
}



// this below function is just used for building the tree
// it has nothing to do with check_if_binary_search_tree() function
bst* insert_in_tree(bst *root2)
{
    bst *temp=new(bst);
    temp->data=50;
    root2=temp;
    temp=new(bst);
    temp->data=30;
    root2->left=temp;
    temp=new(bst);
    temp->data=10;
    root2->left->left=temp;
    temp=new(bst);
    temp->data=1;
    root2->left->left->left=temp;
    temp=new(bst);
    temp->data=40;
    root2->left->right=temp;
    temp=new(bst);
    temp->data=35;
    root2->left->right->left=temp;
    temp=new(bst);
    temp->data=33;
    root2->left->right->left->left=temp;
    temp=new(bst);
    temp->data=37;
    root2->left->right->left->right=temp;
    temp=new(bst);
    temp->data=45;
    root2->left->right->right=temp;
    temp=new(bst);
    temp->data=60;
    root2->right=temp;
    temp=new(bst);
    temp->data=55;
    root2->right->left=temp;
    temp=new(bst);
    temp->data=80;
    root2->right->right=temp;
    temp=new(bst);
    temp->data=70;
    root2->right->right->left=temp;
    temp=new(bst);
    temp->data=75;
    root2->right->right->left->right=temp;
    temp=new(bst);
    temp->data=100;
    root2->right->right->right=temp;
    return root2;
}

bst* insert_in_tree2(bst *root2)
{
    bst *temp=new(bst);
    temp->data=50;
    root2=temp;
    temp=new(bst);
    temp->data=30;
    root2->left=temp;
    temp=new(bst);
    temp->data=10;
    root2->left->left=temp;
    temp=new(bst);
    temp->data=1;
    root2->left->left->left=temp;
    temp=new(bst);
    temp->data=40;
    root2->left->right=temp;
    temp=new(bst);
    temp->data=35;
    root2->left->right->left=temp;
    temp=new(bst);
    temp->data=33;
    root2->left->right->left->left=temp;
    temp=new(bst);
    temp->data=37;
    root2->left->right->left->right=temp;
    temp=new(bst);
    temp->data=4;
    root2->left->right->right=temp;
    temp=new(bst);
    temp->data=60;
    root2->right=temp;
    temp=new(bst);
    temp->data=55;
    root2->right->left=temp;
    temp=new(bst);
    temp->data=80;
    root2->right->right=temp;
    temp=new(bst);
    temp->data=70;
    root2->right->right->left=temp;
    temp=new(bst);
    temp->data=75;
    root2->right->right->left->right=temp;
    temp=new(bst);
    temp->data=100;
    root2->right->right->right=temp;
    return root2;
}



