// A C++ program to demonstrate adjacency list
// representation of graphs using sets
#include <bits/stdc++.h>
using namespace std;
 
struct Graph {
    int V;
    set<int, greater<int> >* adjList;
};
 
// A utility function that creates a graph of V vertices
Graph* createGraph(int V)
{
    Graph* graph = new Graph;
    graph->V = V;
 
    // Create an array of sets representing
    // adjacency lists.  Size of the array will be V
    graph->adjList = new set<int, greater<int> >[V];
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new
    // element is inserted to the adjacent
    // list of src.
    graph->adjList[src].insert(dest);
 
    // Since graph is undirected, add an edge
    // from dest to src also
    graph->adjList[dest].insert(src);
}
 
// A utility function to print the adjacency
// list representation of graph
void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->V; ++i) {
        set<int, greater<int> > lst = graph->adjList[i];
        cout << endl << "Adjacency list of vertex "
             << i << endl;
 
        for (auto itr = lst.begin(); itr != lst.end(); ++itr)
            cout << *itr << " ";
        cout << endl;
    }
}
 
// Searches for a given edge in the graph
void searchEdge(Graph* graph, int src, int dest)
{
    auto itr = graph->adjList[src].find(dest);
    if (itr == graph->adjList[src].end())
        cout << endl << "Edge from " << src
             << " to " << dest << " not found."
             << endl;
    else
        cout << endl << "Edge from " << src
             << " to " << dest << " found."
             << endl;
}
 
// Driver code
int main()
{
    // Create the graph given in the above figure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // Print the adjacency list representation of
    // the above graph
    printGraph(graph);
 
    // Search the given edge in the graph
    searchEdge(graph, 2, 1);
    searchEdge(graph, 0, 3);
 
    return 0;
}
Output
Adjacency list of vertex 0
4 1 

Adjacency list of vertex 1
4 3 2 0 

Adjacency list of vertex 2
3 1 

Adjacency list of vertex 3
4 2 1 

Adjacency list of vertex 4
3 1 0 

Edge from 2 to 1 found.

Edge from 0 to 3 not found.
Pros: Queries like whether there is an edge from vertex u to vertex v can be done in O(log V).
Cons: 

Adding an edge takes O(log V), as opposed to O(1) in vector implementation.
Graphs containing parallel edge(s) cannot be implemented through this method.
Further Optimization of Edge Search Operation using unordered_set (or hashing): 
The edge search operation can be further optimized to O(1) using unordered_set which uses hashing internally.


// A C++ program to demonstrate adjacency list
// representation of graphs using sets
#include <bits/stdc++.h>
using namespace std;
 
struct Graph {
    int V;
    unordered_set<int>* adjList;
};
 
// A utility function that creates a graph of
// V vertices
Graph* createGraph(int V)
{
    Graph* graph = new Graph;
    graph->V = V;
 
    // Create an array of sets representing
    // adjacency lists. Size of the array will be V
    graph->adjList = new unordered_set<int>[V];
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest)
{
    // Add an edge from src to dest. A new
    // element is inserted to the adjacent
    // list of src.
    graph->adjList[src].insert(dest);
 
    // Since graph is undirected, add an edge
    // from dest to src also
    graph->adjList[dest].insert(src);
}
 
// A utility function to print the adjacency
// list representation of graph
void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->V; ++i) {
        unordered_set<int> lst = graph->adjList[i];
        cout << endl << "Adjacency list of vertex "
             << i << endl;
 
        for (auto itr = lst.begin(); itr != lst.end(); ++itr)
            cout << *itr << " ";
        cout << endl;
    }
}
 
// Searches for a given edge in the graph
void searchEdge(Graph* graph, int src, int dest)
{
    auto itr = graph->adjList[src].find(dest);
    if (itr == graph->adjList[src].end())
        cout << endl << "Edge from " << src
             << " to " << dest << " not found."
             << endl;
    else
        cout << endl << "Edge from " << src
             << " to " << dest << " found."
             << endl;
}
 
// Driver code
int main()
{
    // Create the graph given in the above figure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // Print the adjacency list representation of
    // the above graph
    printGraph(graph);
 
    // Search the given edge in the graph
    searchEdge(graph, 2, 1);
    searchEdge(graph, 0, 3);
 
    return 0;
}
