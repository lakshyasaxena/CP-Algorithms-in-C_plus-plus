#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  Given Undirected Graph
//
//              1        3
//             /        /
//            /        /
//           0        2____
//            \    _/ |    \
//             \ _/   |     \
//              8     5      4
//               \   /       |
//                \ /        |
//                 6---------7
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
    ll nodes=9,edges=20;
    vector <vector <ll>> graph(nodes);
    graph[0].push_back(1);graph[0].push_back(8);
    graph[1].push_back(0);
    graph[2].push_back(3);graph[2].push_back(4);graph[2].push_back(5);graph[2].push_back(8);
    graph[3].push_back(2);
    graph[4].push_back(2);graph[4].push_back(7);
    graph[5].push_back(2);graph[5].push_back(6);
    graph[6].push_back(5);graph[6].push_back(7);graph[6].push_back(8);
    graph[7].push_back(4);graph[7].push_back(6);
    graph[8].push_back(0);graph[8].push_back(2);graph[8].push_back(6);

    adjacency_list_traverse(graph);
    ll cn;  // Current Node/starting node
    cn=0;
    bfs(graph,cn);
    return 0;
}
