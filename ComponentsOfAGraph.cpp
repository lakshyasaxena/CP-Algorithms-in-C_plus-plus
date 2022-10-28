Connected components in a graph refer to a set of vertices 
that are connected to each other by direct or indirect paths. 
In other words, a set of vertices in a graph is a connected component 
if every node in the graph can be reached from every other node in the graph.

Algorithm:
step-1 Mark all vertices as non visited
step-2 Select any vertex (say V). 
step-3 If V is not visited , 
            i)  call function DFS_Connect_Comp ( V ) 
            ii) print new line character.
step-4 If V is visited, Go to step-2 and choose another vertex.

DFS_Connect_Comp ( V )
    step-1 Mark V as visited.
    step-2 Print V 
    step-3 Do following for every adjacent vertex 'U' of 'V'
            If U is not visited, call recursively for DFS_Connect_Comp( U ).
            
            
C++ implementation of the above Algorithm

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V; // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
 
    // A function used by DFS
    void DFS_Connect_Comp(int v, bool visited[]);
 
public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int u);
    void connectedComponents();
};

void Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            DFS_Connect_Comp(v, visited);
 
            cout << "\n";
        }
    }
    delete[] visited;
}
