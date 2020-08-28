#include <bits/stdc++.h>
#define node first
#define weight second
using namespace std;
typedef long long ll;
//
//  You are given an Undirected Weighted Graph, one source node and one destination node
//  You have to find the maximum path that can be taken to reach destination node starting from source node
//  You have to print the path chosen and the cost of the path
//
//    Consider the following Non-directed Weighted Graph
//
//                                (1)
//                                / \_
//                             2 /    \_
//                          ____|       \_ 4
//                         /              \______
//                        /                      \         12
//              source-->(0)                      (2)--------------(7)
//                        | \_                   _/ |
//                        |   \_ 3           5 _/   |
//                        |     \_           _/     |
//                        |       \_       _/       |                   (8)
//                        |         \_   _/         |                    |
//                      1 |          _(6)_          | 6                  |
//                        |        _/  |  \_        |                    |13
//                        |    8 _/    |    \_ 7    |                    |
//                        |    _/      |      \_    |                    |
//                        |  _/        |        \_  |                   (9)
//                        | /          |          \ |
//                       (3)           | 9         (5)--> destination
//                         \_          |          _/
//                           \         |        _/
//                            \_       |      _/
//                          10  \      |    _/  11
//                               \____(4)__/
//
//
//     In the above graph, if you choose the following path:
//     0 1 2 6 3 4 5
//     You will get the maximum cost of 40
//     Try on different source node and destination node
//
void traverse_path(vector <ll> &path)
{
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<"\n";
}
void traverse(vector <vector <pair <ll,ll>>> &v1)
{
    cout<<"Adjacency List Traversal\n";
    for(int i=0;i<v1.size();i++)
    {
        cout<<"("<<i<<") -> ";
        for(int j=0;j<v1[i].size();j++)
        {
            cout<<v1[i][j].node<<" ["<<v1[i][j].weight<<"] ";
        }
        cout<<"\n";
    }
}
void dfs(vector <vector <pair <ll,ll>>> &graph,vector <bool> va,ll source,ll &destination,ll &max_dis,ll cost,ll new_cost,vector <ll> &current_path,vector <ll> &max_path)
{
    current_path.push_back(source); //cout<<"source = "<<source<<"\n";
    cost+=new_cost;
    if(source==destination) // base condition
    {
        if(max_dis<cost)
        {
            max_dis=cost;
            max_path.clear();
            max_path=current_path;
        }
        //cout<<"base condition reached backtrack\n";
        return;
    }
    for(int i=0;i<graph[source].size();i++)
    {
        if(va[graph[source][i].node]==false)
        {
            va[graph[source][i].node]=true;
            dfs(graph,va,graph[source][i].node,destination,max_dis,cost,graph[source][i].weight,current_path,max_path);
            va[graph[source][i].node]=false;// backtrack condition
            current_path.pop_back();
        }
    }
}
ll get_max_distance(vector <vector <pair <ll,ll>>> &graph,ll source,ll destination,vector <ll> &max_path)
{
    ll max_dis=-100;
    ll cost=0;
    vector <ll> current_path;
    vector <bool> va(graph.size(),false);
    va[source]=true;
    dfs(graph,va,source,destination,max_dis,cost,0,current_path,max_path);
    return max_dis;
}
int main()
{
    ll n,e;
    n=10;e=13;
    vector <vector <pair <ll,ll>>> graph(n);
    // Use the below code to process your own input
    /*cin>>n>>e;
    while(e--)
    {
        ll n1,n2,w;
        cin>>n1>>n2>>w;
        graph[n1].push_back(make_pair(n2,w));
    }
    */
    graph[0].push_back(make_pair(3,1));  graph[3].push_back(make_pair(0,1));
    graph[0].push_back(make_pair(1,2));  graph[1].push_back(make_pair(0,2));
    graph[0].push_back(make_pair(6,3));  graph[6].push_back(make_pair(0,3));
    graph[1].push_back(make_pair(2,4));  graph[2].push_back(make_pair(1,4));
    graph[6].push_back(make_pair(2,5));  graph[2].push_back(make_pair(6,5));
    graph[2].push_back(make_pair(5,6));  graph[5].push_back(make_pair(2,6));
    graph[6].push_back(make_pair(5,7));  graph[5].push_back(make_pair(6,7));
    graph[6].push_back(make_pair(3,8));  graph[3].push_back(make_pair(6,8));
    graph[6].push_back(make_pair(4,9));  graph[4].push_back(make_pair(6,9));
    graph[3].push_back(make_pair(4,10)); graph[4].push_back(make_pair(3,10));
    graph[4].push_back(make_pair(5,11)); graph[5].push_back(make_pair(4,11));
    graph[2].push_back(make_pair(7,12)); graph[7].push_back(make_pair(2,12));
    graph[8].push_back(make_pair(9,13)); graph[9].push_back(make_pair(8,13));
    traverse(graph);
    ll source,destination;
    source=0;
    destination=5;
    vector <ll> path;
    ll max_dis=get_max_distance(graph,source,destination,path);
    cout<<"\n\nWe will choose the following path in our graph\n";
    traverse_path(path);
    cout<<"Maximum distance possible is "<<max_dis<<"\n";
    return 0;
}
