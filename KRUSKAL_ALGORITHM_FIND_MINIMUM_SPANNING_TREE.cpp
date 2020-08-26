#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  You are given an Undirected Graph starting with zero index node, may or may not have cycles
//  You have to find it's Minimum Spanning Tree
//  We will use KRUSKAL'S ALGORITHM to solve this problem
//  We will use UNION FIND Algorithm (Disjoint Set Union) to detect cycle at any point in MST
//
//  Consider the following Undirected Weighted Graph                                         This is Minimum Spanning Tree
//
//                           4                                                                      4
//                 (1)----------------(2)                                                 (1)-----------------(2)
//                /  \                / \                                                 /
//               /    \              /   \                                               /
//              /      \            /     \                                             /
//            1/        \5        8/       \12                                        1/
//            /          \        /         \                                         /
//           /            \      /           \                                       /
//          /              \    /             \                                     /
//         /       2        \  /       9       \        13                         /       2                9                13
//       (0)----------------(6)----------------(3)-------------(7)     --->      (0)---------------(6)---------------(3)------------(7)
//         \               /  \                /                                   \
//          \             /    \              /                                     \
//           \           /      \            /                                       \
//            \ 3      6/      10\          /11                                       \
//             \       /          \        /                                         3 \
//              \     /            \      /                                             \
//               \   /              \    /                                               \
//                \ /       7        \  /                                                 \        7
//                (4)----------------(5)                                                  (4)---------------(5)
//
//   Now run the code to generate the MST
//
class Edge_Of_Graph
{
public:
    ll node1;
    ll node2;
    ll weight;
};
typedef Edge_Of_Graph eog;

bool sort_in_my_way(eog &a,eog &b)
{
    return(a.weight>b.weight);
}

ll find_parent(ll edge,vector <ll> &parent_array)
{
    if(edge==parent_array[edge]) // base condition
    {
        return edge;
    }
    find_parent(parent_array[edge],parent_array);
}

ll find_minimum_spanning_tree(vector <eog> &graph,ll &nodes, vector <eog> &MST)
{
    ll cost=0;
    ll count=0;
    vector <ll> parent_array(nodes);
    for(int i=0;i<nodes;i++) { parent_array[i]=i; }
    ll index=-1;
    while(count!= (nodes-1))
    {
        ll source_node=graph[++index].node1;
        ll destination_node=graph[index].node2;
        source_node=find_parent(source_node,parent_array);
        destination_node=find_parent(destination_node,parent_array);
        if(source_node!=destination_node)
        {
            parent_array[source_node]=destination_node;
            cost+=graph[index].weight;
            MST[count].node1=graph[index].node1;
            MST[count].node2=graph[index].node2;
            MST[count++].weight=graph[index].weight;
        }
    }
    return cost;
}


void traverse(vector <eog> &graph)
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<" "<<graph[i].node1<<" -> "<<graph[i].node2<<" costs "<<graph[i].weight<<"\n";
    }
}
int main(void)
{
    ll nodes,edges;
    nodes=8; edges=13;
    vector <eog> graph(edges);
    // Use the below code to test your given input
    /*cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        ll node1,node2,weight;
        cin>>node1>>node2>>weight;
        graph[i].node1=node1;graph[i].node2=node2;graph[i].weight=weight;
    } */

    // This is your Default Graph
    graph[0].node1=4;graph[0].node2=6;graph[0].weight=6;
    graph[1].node1=6;graph[1].node2=5;graph[1].weight=10;
    graph[2].node1=3;graph[2].node2=7;graph[2].weight=13;
    graph[3].node1=6;graph[3].node2=3;graph[3].weight=9;
    graph[4].node1=2;graph[4].node2=3;graph[4].weight=12;
    graph[5].node1=0;graph[5].node2=4;graph[5].weight=3;
    graph[6].node1=1;graph[6].node2=2;graph[6].weight=4;
    graph[7].node1=4;graph[7].node2=5;graph[7].weight=7;
    graph[8].node1=0;graph[8].node2=6;graph[8].weight=2;
    graph[9].node1=6;graph[9].node2=2;graph[9].weight=8;
    graph[10].node1=5;graph[10].node2=3;graph[10].weight=11;
    graph[11].node1=1;graph[11].node2=6;graph[11].weight=5;
    graph[12].node1=0;graph[12].node2=1;graph[12].weight=1;
    //traverse(graph);
    sort(graph.begin(),graph.end(),sort_in_my_way);
    cout<<"After sorting the GRAPH on the basis of WEIGHTS:\n";
    traverse(graph);
    vector <eog> MST(nodes-1);
    ll cost=find_minimum_spanning_tree(graph,nodes,MST);
    cout<<"\nMinimim cost is = "<<cost<<"\n";
    cout<<"And your MST is :\n";
    traverse(MST);
    return 0;
}
