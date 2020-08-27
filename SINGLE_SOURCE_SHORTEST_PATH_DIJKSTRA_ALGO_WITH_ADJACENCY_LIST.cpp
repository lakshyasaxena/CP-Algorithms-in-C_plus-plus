#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  Given a weighted graph, can be directed or undirected but has to be strongly connected graph
//  We have to find SINGLE SOURCE SHORTEST PATH
//  That means, from one source node, we have to find shortest path to reach all other nodes
//  We will use DIJKSTRA ALGORITHM to solve this
//
//  Consider the following graph for this problem
//
//                    5             3
//              (1)-------(3)-------------(5)
//             /          /|               |
//           4/          / |               |
//           /          /  |               |
//          /          /   |               |
//       (0)         5/    |4              |8
//          \        /     |               |
//           \      /      |               |
//           8\    /       |               |
//             \  /   9    |       1       |
//             (2)--------(4)-------------(6)
//
//    We have taken 0 as our source node
//    Try choosing different source nodes with same code
//
void traverse(vector <vector <pair <ll,ll>>> &v1)
{
    cout<<"Adjacency Linked List Traversal with weights in square brackets []\n";
    cout<<"Index      Connections\n";
    for(int i=0;i<v1.size();i++)
    {
        cout<<" ("<<i<<") ->  ";
        for(int j=0;j<v1[i].size();j++)
        {
            cout<<v1[i][j].first<<" ["<<v1[i][j].second<<"] ";
        }
        cout<<"\n";
    }
}
void traverse(vector <pair <bool,ll>> &visited_array,ll source)
{
    cout<<"From source node ["<<source<<"] to nodes\n";
    for(int i=0;i<visited_array.size();i++)
    {
        cout<<"["<<i<<"] minimum cost is = "<<visited_array[i].second<<"\n";
    }
}
void initialize(vector <pair <bool,ll>> &visited_array)
{
    for(int i=0;i<visited_array.size();i++)
    {
        visited_array[i].first=false;
        visited_array[i].second=INT_MAX;
    }
}

ll find_smallest_node(vector <pair <bool,ll>> &visited_array)
{
    ll cost=INT_MAX;
    ll node=-1;
    for(int i=0;i<visited_array.size();i++)
    {
        if(visited_array[i].first==false && visited_array[i].second <cost )
        {
            cost=visited_array[i].second;
            node=i;
        }
    }
    return node;
}

void dijkstra_algorithm(ll source,vector <vector <pair <ll,ll>>> &graph, vector <pair <bool,ll>> &visited_array)
{
    visited_array[source].second=0;
    for(int i=0;i<graph.size();i++)
    {
        ll smallest_node=find_smallest_node(visited_array);
        visited_array[smallest_node].first=true;
        ll cost=visited_array[smallest_node].second;
        for(int j=0;j<graph[smallest_node].size();j++)
        {
            visited_array[graph[smallest_node][j].first].second=min(visited_array[graph[smallest_node][j].first].second ,( cost + graph[smallest_node][j].second) );
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll n,e;
    n=7;  // n are the nodes in graph
    e=9;  // e are the edges in graph
    vector <vector <pair <ll,ll>>> graph(n);
    // use the below code for providing your own input
    //cin>>n>>e;
    /*while(e--)
    {
        ll node1,node2,weight;
        cin>>node1>>node2>>weight;
        graph[node1].push_back(make_pair(node2,weight));
    }
    */
    graph[0].push_back(make_pair(1,4));    graph[1].push_back(make_pair(0,4));
    graph[0].push_back(make_pair(2,8));    graph[2].push_back(make_pair(0,8));
    graph[1].push_back(make_pair(3,5));    graph[3].push_back(make_pair(1,5));
    graph[2].push_back(make_pair(3,5));    graph[3].push_back(make_pair(2,5));
    graph[2].push_back(make_pair(4,9));    graph[4].push_back(make_pair(2,9));
    graph[3].push_back(make_pair(4,4));    graph[4].push_back(make_pair(3,4));
    graph[3].push_back(make_pair(5,3));    graph[5].push_back(make_pair(3,3));
    graph[4].push_back(make_pair(6,1));    graph[6].push_back(make_pair(4,1));
    graph[5].push_back(make_pair(6,8));    graph[6].push_back(make_pair(5,8));
    traverse(graph);cout<<"\n\n";
    ll source;
    //cin>>source;
    source=0;
    vector <pair <bool,ll>> visited_array(n);
    initialize(visited_array);
    dijkstra_algorithm(source,graph,visited_array);
    traverse(visited_array,source);
    cout<<"\n\n";
    return 0;
}
// code contributed by LAKSHYA SAXENA
