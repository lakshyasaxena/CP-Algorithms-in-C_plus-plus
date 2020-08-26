#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//  You are given an Undirected Graph starting with zero index node, may or may not have cycles
//  You have to count the number of cycles in that graph
//  We will use UNION FIND Algorithm (Disjoint Set Union) to solve this problem
//
//  Consider the following Graph
//
//             (1)--------(2)
//             /  \       / \
//            /    \     /   \
//           /      \   /     \
//          /        \ /       \
//        (0)--------(6)------(3)--------(7)
//          \        / \       /
//           \      /   \     /
//            \    /     \   /
//             \  /       \ /
//             (4)--------(5)
//
//   Now run the code to count the No. of Cycles
//
class Node_of_Graph
{
public:
    ll node1;
    ll node2;
};
typedef Node_of_Graph nof;

ll find_parent(ll edge,vector <ll> &parent_array)
{
    if(parent_array[edge]==edge) // base condition
    {
        return edge;
    }
    find_parent(parent_array[edge],parent_array);
}

ll count_cycles_in_undirected_graph(vector <nof> &v1,ll nodes)
{
    ll count_edges=0;
    // build one parent array
    vector <ll> parent_array(nodes);
    for(int i=0;i<parent_array.size();i++) parent_array[i]=i;

    // traverse your graph edges in any order and do the following
    for(int i=0;i<v1.size();i++)
    {
        ll source_edge,destination_edge;
        source_edge=v1[i].node1;
        destination_edge=v1[i].node2;
        source_edge=find_parent(source_edge,parent_array);
        destination_edge=find_parent(destination_edge,parent_array);
        (source_edge!=destination_edge) ? parent_array[source_edge]=destination_edge : count_edges++;
    }
    return count_edges;
}

void traverse(vector <nof> &v1)
{
    cout<<"The given graph is as follows :\n";
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i].node1<<" connects "<<v1[i].node2<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll nodes,edges;
    nodes=8;
    edges=13;
    vector <nof> graph(edges);
    // use the below commented code when you want to give your input
    /*cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        ll node1,node2;
        cin>>node1>>node2;
        graph[i].node1=node1;
        graph[i].node2=node2;
    }
    */
    graph[0].node1=0;graph[0].node2=1;
    graph[1].node1=0;graph[1].node2=6;
    graph[2].node1=0;graph[2].node2=4;
    graph[3].node1=1;graph[3].node2=2;
    graph[4].node1=1;graph[4].node2=6;
    graph[5].node1=4;graph[5].node2=6;
    graph[6].node1=4;graph[6].node2=5;
    graph[7].node1=6;graph[7].node2=2;
    graph[8].node1=6;graph[8].node2=3;
    graph[9].node1=6;graph[9].node2=5;
    graph[10].node1=5;graph[10].node2=3;
    graph[11].node1=2;graph[11].node2=3;
    graph[12].node1=3;graph[12].node2=7;
    traverse(graph);
    ll c=count_cycles_in_undirected_graph(graph,nodes);
    cout<<"\n\nThere are "<<c<<" cycles in the graph\n\n";
    return 0;
}
