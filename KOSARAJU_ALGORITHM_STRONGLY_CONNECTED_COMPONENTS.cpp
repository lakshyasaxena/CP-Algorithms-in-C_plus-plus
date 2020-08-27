#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
//  We are given an Undirected Graph
//  We have to find all of it's strongly Connected Components (find out it's definition)
//  We will be using Kosaraju's Algorithm
//
//   Consider the following Graph
//
//   (0)----------->(1)            (5)
//    ^              |              ^ \
//    |              |              |  \___             __________
//    |              |              |      |           |          |
//    |              |              |      |           |          |
//    |              V              |      V           |          V
//   (3)<-----------(2)----------->(4)<---(6)<--------(7)<-------(8)-------->(9)
//
//
//  In the above graph we have 4 strongly connected components
//  They are as follow:
//  0 1 2 3
//  4 5 6
//  7 8
//  9
//
void dfs(vector <vector <ll>> &graph, vector <bool> &va,ll current,stack <ll> &s)
{
    va[current]=true;
    cout<<current<<" ";
    for(int i=0;i<graph[current].size();i++)
    {
        if(va[graph[current][i] ]==false  )
        {
            dfs(graph,va,graph[current][i],s);
        }
    }
    s.push(current);
}
void dfs_traversal(vector <vector <ll>> &graph,stack <ll> &s)
{
    cout<<"DFS Traversal\n";
    vector <bool> va(graph.size(),false);
    for(int i=0;i<va.size();i++)
    {
        if(!va[i]==true)
        {
            dfs(graph,va,i,s);
        }
    }
}
vector <vector <ll>> transpose(vector <vector <ll>> &graph)
{
    vector <vector <ll>> tg(graph.size());// tg -> transpose graph
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            tg[graph[i][j]].push_back(i);
        }
    }
    return tg;
}
void krdfs(vector <bool> &va,ll current, vector <vector <ll>> &graph, vector <ll> &c)
{
    c.push_back(current);
    va[current]=true;
    for(int i=0;i<graph[current].size();i++)
    {
        if(va[graph[current][i]]==false)
        {
            krdfs(va,graph[current][i],graph,c);
        }
    }
}
void kosaraju_dfs(vector <vector <ll>> &graph,stack <ll> &s,vector <vector <ll>> &cc)
{
    vector <bool> va(graph.size(),false);  // va stands for visited array
    vector <ll> c;  // c stands for component
    while(!s.empty())
    {
        if(va[s.top()]==false)
        {
            krdfs(va,s.top(),graph,c);
            cc.push_back(c);
            c.clear();
        }
        s.pop();
    }
}
void traverse(vector <vector <ll>> &graph)
{
    cout<<"Adjacency Linked List of the Directed Graph \n";
    for(int i=0;i<graph.size();i++)
    {
        cout<<"("<<i<<")-> ";
        for(int j=0;j<graph[i].size();j++) { cout<<graph[i][j]<<" "; } cout<<"\n";
    }
}
void components_traverse(vector <vector <ll>> &v1)
{
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v1[i].size();j++) { cout<<v1[i][j]<<" "; } cout<<"\n";
    }
}
int main()
{
    ll nodes,edges;
    nodes=10;
    edges=12;
    vector <vector <ll>> graph(nodes);
    vector <vector <ll>> transpose_graph;
    vector <vector <ll>> connected_components;
    stack <ll> s;
    graph[0].push_back(1); graph[1].push_back(2);
    graph[2].push_back(3); graph[2].push_back(4);
    graph[3].push_back(0); graph[4].push_back(5);
    graph[5].push_back(6); graph[6].push_back(4);
    graph[7].push_back(6); graph[7].push_back(8);
    graph[8].push_back(7); graph[8].push_back(9);
    traverse(graph); cout<<"\n";
    dfs_traversal(graph,s);cout<<"\n\n";
    transpose_graph=transpose(graph);
    //traverse(transpose_graph);
    kosaraju_dfs(transpose_graph,s,connected_components);
    cout<<"We have "<<connected_components.size()<<" STRONGLY CONNECTED COMPONENTS\n";
    components_traverse(connected_components);
    return 0;
}
