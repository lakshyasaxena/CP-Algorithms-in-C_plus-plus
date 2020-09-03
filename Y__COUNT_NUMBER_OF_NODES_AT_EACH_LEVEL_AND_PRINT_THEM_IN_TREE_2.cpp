#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in input_nodes   // use it for efficiency
#define pb push_back    // use this macro for saving time and efficiency

//    You are given a Binary TREE (may be BST)
//    You have to print nodes of tree at each level and count them
//    Time Complexity O(N) , where N is the number of nodes in tree
//
//    Consider the below given BST for reference
//
//
//                         root->100                        -->>   Level 1   ( 1 node)   100
//                              /   \
//                             /     \
//                            /       \
//                           /         \
//                          /           \
//                         /             \
//                        /               \
//                       /                 \
//                      50                 150              -->>   Level 2   ( 2 nodes)  50,150
//                     / \                 /  \
//                    /   \               /    \
//                   /     \             /      \
//                  /       \           /        \
//                 /         \         /          \
//               25          75       125          200      -->>   Level 3   ( 4 nodes)   25,75,125,200
//               / \                 /   \         / \
//              /   \               /     \       /   \
//            10     30            110    130   175   300   -->>   Level 4   ( 6 nodes)   10,30,110,130,175,300
//           /  \      \             \          /
//          /    \      \             \        /
//         5     12     40            115    160            -->>   Level 5   ( 5 nodes)   5,12,40,115,160
//
//
//     Try to print data as above format
//     Data structure needed - 2 Queues
//     Time complexity O(nodes)
//
//
class Node_Of_Binary_Tree
{
public:
    ll data;
    Node_Of_Binary_Tree *left;  // left pointer
    Node_Of_Binary_Tree *right; // right pointer
    Node_Of_Binary_Tree()
    {
        data=0;
        left=right=NULL;
    }
};
typedef Node_Of_Binary_Tree bst;
// bst stands for Binary Search Tree


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
void level_order_traversal(bst *root)
{
    queue <bst*> q1;  // for all odd level nodes
    queue <bst*> q2;  // for all even level nodes
    q1.push(root);
    int start=0;
    ll c=0;
    ll total=0;
    while(!q1.empty() || !q2.empty())
    {
        c=0;
        cout<<"Level "<<++start<<" ->  ";
        while(!q1.empty())
        {
            c++;
            bst *temp=q1.front();
            cout<<temp->data<<"  ";
            q1.pop();
            if(temp->left!=NULL)
            {
                q2.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q2.push(temp->right);
            }
        }
       cout<<"\n   [ Number of nodes = "<<c<<"]\n";

        total+=c;
        c=0;
        cout<<"Level "<<++start<<" ->  ";
        while(!q2.empty())
        {
            c++;
            bst *temp=q2.front();
            cout<<temp->data<<"  ";
            q2.pop();
            if(temp->left!=NULL)
            {
                q1.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q1.push(temp->right);
            }
        }
        cout<<"\n   [ Number of nodes = "<<c<<"]\n";
        total+=c;
    }
    cout<<"Total nodes = "<<total<<"\n";

}
int main()
{
    bst *root=NULL;
    ll nodes=18;
    vector <ll> input_nodes;   // macro used for it is -> in
    in.pb(100);     in.pb(50);
    in.pb(150);     in.pb(25);
    in.pb(75);      in.pb(125);
    in.pb(200);     in.pb(10);
    in.pb(30);      in.pb(110);
    in.pb(130);     in.pb(175);
    in.pb(300);     in.pb(5);
    in.pb(12);      in.pb(40);
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
    cout<<"\nPre-Order Traversal\n";
    preorder_traversal(root);
    cout<<"\n\nIn-Order Traversal\n";
    inorder_traversal(root);
    cout<<"\n\n";
    level_order_traversal(root);
    return 0;
}

