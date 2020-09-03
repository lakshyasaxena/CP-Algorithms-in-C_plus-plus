#include <bits/stdc++.h>
#define in input_nodes
#define pb push_back
using namespace std;
typedef long long ll;
//    Given a Binary Tree (may be BST) and two nodes
//    You have to find the LCA (least common ancestor) of these two nodes from the TREE
//    Consider the below BST for reference
//    Note: This is a brute force solution in which we first trace the path of
//          both the nodes and then compute LCA.
//
//
//
//                             root ->  12
//                                     /  \
//                                    /    \
//                                   /      \
//                                  /        \
//                                 /          \
//                                /            \
//                               /              \
//                              10              20
//                             /  \            /  \
//                            /    \          /    \
//                           /      \        /      \
//                          5       11      15      22
//                         / \             /  \       \
//                        /   \           /    \       \
//                       3     7         13    18      30
//                            /               /  \
//                           /               /    \
//                          6               17    19
//
//
//           LCA (6, 19)  = 12
//           LCA (17, 30) = 20
//           LCA (6, 11)  = 10
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
//*********************************************************************************************
void trace_path(bst *root,stack <ll> &s1,ll &target)
{
    if(root==NULL) return;
    s1.push(root->data);
    if(s1.top()!=target)  { trace_path(root->left,s1,target);  }
    if(s1.top()!=target)  { trace_path(root->right,s1,target); }
    if(s1.top()!=target)  { s1.pop();                          }
}
//**********************************************************************************************
void traverse(stack <ll> path1)
{
    while(!path1.empty())
    {
        cout<<path1.top()<<" ";
        path1.pop();
    }
}
ll get_lca(stack <ll> &path1,stack <ll> &path2)
{
    stack <ll> s1; // for reversing stack path1
    stack <ll> s2; // for reversing stack path2
    while(!path1.empty())
    {
        s1.push(path1.top());
        path1.pop();
    }
    while(!path2.empty())
    {
        s2.push(path2.top());
        path2.pop();
    }
    ll lca_node=-1;
    while(!s1.empty() && !s2.empty())
    {
        if(s1.top()==s2.top())
        {
            lca_node=s1.top();
            s1.pop();
            s2.pop();
            continue;
        }
        break;
    }
    return lca_node;
}
int main()
{
    cout<<"Note: This is a brute force solution in which we trace the path and then compute";
    bst *root=NULL;    // pointer that will point the root node
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
        if(root==NULL)
        {
            root=temp;continue;
        }
        input_in_bst(root,temp);
    }
    cout<<"\nPRE-ORDER TRAVERSAL\n";
    preorder_traversal(root);
    cout<<"\nIN-ORDER TRAVERSAL\n";
    inorder_traversal(root);

    // node1 and node2 are the node values upon which we will perform find LCA operation
    ll node1=6;
    ll node2=19;
    cout<<"\n\n  Let Node 1 = "<<node1<<"   and "<<"Node 2 = "<<node2<<"\n\n";
    stack <ll> path1;
    cout<<"Path of Node 1 -> { ";
    trace_path(root,path1,node1);
    traverse(path1);cout<<" }\n";
    stack <ll> path2;
    cout<<"Path of Node 2 -> { ";
    trace_path(root,path2,node2);
    traverse(path2);cout<<" }\n\n";
    cout<<"LCA of ("<<node1<<")"<<" & ("<<node2<<") = "<<get_lca(path1,path2);


    cout<<"\n-----------------------------------------------------------------";
    node1=17;    node2=30;
    cout<<"\n\n  Let Node 1 = "<<node1<<"   and "<<"Node 2 = "<<node2<<"\n\n";
    cout<<"Path of Node 1 -> { ";
    trace_path(root,path1,node1);
    traverse(path1);cout<<" }\n";
    cout<<"Path of Node 2 -> { ";
    trace_path(root,path2,node2);
    traverse(path2);cout<<" }\n\n";
    cout<<"LCA of ("<<node1<<")"<<" & ("<<node2<<") = "<<get_lca(path1,path2);

    cout<<"\n-----------------------------------------------------------------";
    node1=6; node2=11;
    cout<<"\n\n  Let Node 1 = "<<node1<<"   and "<<"Node 2 = "<<node2<<"\n\n";
    cout<<"Path of Node 1 -> { ";
    trace_path(root,path1,node1);
    traverse(path1);cout<<" }\n";
    cout<<"Path of Node 2 -> { ";
    trace_path(root,path2,node2);
    traverse(path2);cout<<" }\n\n";
    cout<<"LCA of ("<<node1<<")"<<" & ("<<node2<<") = "<<get_lca(path1,path2);
    
    cout<<"\n-----------------------------------------------------------------";
    node1=20; node2=30;
    cout<<"\n\n  Let Node 1 = "<<node1<<"   and "<<"Node 2 = "<<node2<<"\n\n";
    cout<<"Path of Node 1 -> { ";
    trace_path(root,path1,node1);
    traverse(path1);cout<<" }\n";
    cout<<"Path of Node 2 -> { ";
    trace_path(root,path2,node2);
    traverse(path2);cout<<" }\n\n";
    cout<<"LCA of ("<<node1<<")"<<" & ("<<node2<<") = "<<get_lca(path1,path2);
    cout<<"\n";
    return 0;
}
