#include <iostream>
#include "Graph.h"

int main()
{
    map<Vertex,vector<Vertex>> Adj;
    Adj[Vertex{1}] = vector<Vertex>{Vertex{2},Vertex{3},Vertex{4},Vertex{5}};
    Adj[Vertex{2}] = vector<Vertex>{Vertex{1},Vertex{3},Vertex{4}};
    Adj[Vertex{3}] = vector<Vertex>{Vertex{1},Vertex{2},Vertex{4},Vertex{5}};
    Adj[Vertex{4}] = vector<Vertex>{Vertex{1},Vertex{2},Vertex{3},Vertex{5}};
    Adj[Vertex{5}] = vector<Vertex>{Vertex{1},Vertex{3},Vertex{4}};
    Graph graph(Adj);
    bool isPlanar = graph.IsPlanar();
    std::cout << "Your graph is: "<<(isPlanar?"planar":"not planar")<< std::endl;

    return 0;
}

