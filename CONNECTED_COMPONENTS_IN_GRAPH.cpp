
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  Given Undirected Graph
//
//    1-----0      3        5
//    |            |
//    |            |
//    |            |
//    2            4
//
//   Find all connected components of the graph
//
void traverse(vector <vector <ll>> &graph)
{
    cout<<"Adjacency List Representation\n";
    for(int i=0;i<graph.size();i++)
    {
        cout<<"Node "<<i<<" -> ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void bfs(vector <vector <ll>> &graph,vector <bool> &va,ll cn)
{
    queue <ll> q;
    q.push(cn);
    va[cn]=true;
    while(!q.empty())
    {
        cn=q.front();
        q.pop();
        cout<<cn<<" ";
        for(int i=0;i<graph[cn].size();i++)
        {
            if(va[graph[cn][i]]==false)
            {
                va[graph[cn][i]]=true;
                q.push(graph[cn][i]);
            }
        }
    }
    cout<<"\n";
}
void connected_component(vector <vector <ll>> &graph)
{
    cout<<"CONNECTED COMPONENTS\n";
    vector <bool> va(graph.size(),false);
    ll countt=0;
    for(int i=0;i<va.size();i++)
    {
        if(va[i]==false)
        {
            bfs(graph,va,i);
            countt++;
        }
    }
    cout<<"\nGraph has "<<countt<<" Components\n";
}
int main()
{
    ll nodes=6,edges=6;
    vector <vector <ll>> graph(nodes);
    graph[0].push_back(1);
    graph[1].push_back(0); graph[1].push_back(2);
    graph[2].push_back(1);
    graph[3].push_back(4);
    graph[4].push_back(3);
    traverse(graph);
    connected_component(graph);
    return 0;
}
