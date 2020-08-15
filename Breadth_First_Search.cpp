
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  Given Undirected Graph
//     0--1--2
//     | /| /
//     |/ |/
//     4--3
//
void adjacency_list_traverse(vector <vector <ll>> &graph)
{
    cout<<"Adjacency List Traversal\n";
    for(int i=0;i<graph.size();i++)
    {
        cout<<"Node "<<i<<" -> ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void bfs(vector <vector <ll>> &graph,ll cn)
{
    cout<<"\nBFS TRAVERSAL\n";
    // cn -> stands for current node
    // va -> stands for visited array
    vector <bool> va(graph.size(),false);
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
}
int main()
{
    ll nodes=5,edges=14;
    vector <vector <ll>> graph(nodes);
    graph[0].push_back(1);graph[0].push_back(4);
    graph[1].push_back(0);graph[1].push_back(4);graph[1].push_back(3);graph[1].push_back(2);
    graph[2].push_back(1);graph[2].push_back(3);
    graph[3].push_back(4);graph[3].push_back(1);graph[3].push_back(2);
    graph[4].push_back(0);graph[4].push_back(1);graph[4].push_back(3);

    adjacency_list_traverse(graph);
    ll cn;  // Current Node/starting node
    cn=0;
    bfs(graph,cn);
    return 0;
}
