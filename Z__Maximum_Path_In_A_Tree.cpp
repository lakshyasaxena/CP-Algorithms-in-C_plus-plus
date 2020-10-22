#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// this code is contributed by lakshya saxena
// Problem Statement:
//  You are given an unweighted, undirected tree.
//  Write a program to output the length of the longest path (from one node to another) in that tree.
//  The length of a path in this case is number of edges we traverse from source to destination.
//  Note:
//  1. Since it is a tree, if it has n nodes, it will definitely have (n-1) edges
//  2. If it is tree of n nodes, then a node at max can have (n-1) children
//  Considering all these conditions, Let's take an example:
//  Suppose we have 12 nodes and the connections is as followed
//
//   2 1
//   2 0
//   2 3
//   1 4
//   0 5
//   0 6
//   3 9
//   5 7
//   5 8
//   9 10
//   9 11
//   Based on this data, the structure of tree will be
//
//                            2
//                         _/ | \_
//                       _/   |   \_
//                     _/     |     \_
//                   _/       |       \_
//                 _/         |         \_
//                /           |           \
//               1            0            3
//              /            / \            \
//             /            /   \            \
//            4            5     6            9
//                        / \                / \
//                       /   \              /   \
//                      7     8            10   11
//
//  As you can observed that , the maximum path = 6
//  Below is the code for it's solution
//  Note, in solution we have considered our nodes to start from zero index

class lakshya
{
public:
    bool status=false;
    ll node_max_path=0;
    ll store_path_to_return=0;
};
void traverse_graph(vector <vector <ll> > &graph)
{
    cout<<"Adjacency List of Tree\n";
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"-> ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}
ll dfs(ll current_node,vector <vector <ll> > &graph,vector <lakshya> &visited_array)
{
    visited_array[current_node].status=true;

    vector <ll> all_paths;


    for(int i=0;i<graph[current_node].size();i++)
    {
        if(!visited_array[ graph[current_node][i]   ].status) // not visited
        {
            ll path=dfs(graph[current_node][i],graph,visited_array);
            all_paths.push_back(path);
        }
        else
        {
            //cout<<"already visited\n";
            all_paths.push_back(visited_array[graph[current_node][i]].store_path_to_return);
        }
    }
    //cout<<current_node<<"  -> ";
    //cout<<"All paths are ->  ";
    sort(all_paths.rbegin(),all_paths.rend());
    /*
    for(int i=0;i<all_paths.size();i++)
    {
        cout<<all_paths[i]<<" ";
    }
    cout<<"\n";
    */


    if(all_paths.size()==0) // leaf node
    {
        visited_array[current_node].store_path_to_return=1;
        visited_array[current_node].node_max_path=0;
        return 1;
    }
    if(all_paths.size()==1) // node with only one child
    {
        visited_array[current_node].store_path_to_return=1+all_paths[0];
        visited_array[current_node].node_max_path=all_paths[0];
        return (1+all_paths[0]);
    }
    else  // node with more than one child
    {
        visited_array[current_node].store_path_to_return=1+all_paths[0];
        visited_array[current_node].node_max_path=all_paths[0]+all_paths[1];
        return (1+all_paths[0]);
    }
}
ll get_max_path(vector <vector <ll> > &graph)
{
    vector <lakshya> visited_array(graph.size());
    for(int i=0;i<visited_array.size();i++)
    {
        if(!visited_array[i].status)
        {
            dfs(i,graph,visited_array);
        }
    }
    ll path=INT_MIN;
    for(int i=0;i<visited_array.size();i++)
    {
        //cout<<visited_array[i].store_path_to_return<<"  "<<visited_array[i].node_max_path<<" \n";
        path=max(path,visited_array[i].node_max_path);
    }
    return path;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll nodes=12;
    ll edges=nodes-1;
    vector <vector <ll> > graph(nodes);
    /*  use this to provide manual input
    while(edges--)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
     */
     graph[2].push_back(1);
     graph[2].push_back(0);
     graph[2].push_back(3);
     graph[1].push_back(4);
     graph[0].push_back(5);
     graph[0].push_back(6);
     graph[3].push_back(9);
     graph[5].push_back(7);
     graph[5].push_back(8);
     graph[9].push_back(10);
     graph[9].push_back(11);

    traverse_graph(graph);
    ll path=get_max_path(graph);
    cout<<"max path = "<<path;
    return 0;
}

