#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//
//    Given a Binary Tree
//    You have to determine whether it's a Binary Search Tree or not
//
//    For reference, consider the two Binary Tree given below
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
void check_if_binary_search_tree(bst *root,ll mini,ll maxi,bool &check)
{
    if(root==NULL || check==false) return;

    if(mini > root->data || maxi < root->data)
    {
        check=false;
        return;
    }

    check_if_binary_search_tree(root->left,mini,root->data,check);

    if(check==false) return;

    check_if_binary_search_tree(root->right,root->data,maxi,check);


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
    ll mini=INT_MIN;
    ll maxi=INT_MAX;
    check_if_binary_search_tree(root,mini,maxi,check);
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
    mini=INT_MIN;
    maxi=INT_MAX;
    check_if_binary_search_tree(root2,mini,maxi,check);
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


