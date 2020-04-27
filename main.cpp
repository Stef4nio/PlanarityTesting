#include <iostream>
#include "Graph.h"

int main()
{
    Graph graph;
    graph.Adj[Vertex{1}] = vector<Vertex>{Vertex{2},Vertex{3},Vertex{4}};
    graph.Adj[Vertex{2}] = vector<Vertex>{Vertex{1},Vertex{4},Vertex{5}};
    graph.Adj[Vertex{3}] = vector<Vertex>{Vertex{1},Vertex{5}};
    graph.Adj[Vertex{4}] = vector<Vertex>{Vertex{1},Vertex{2},Vertex{5}};
    graph.Adj[Vertex{5}] = vector<Vertex>{Vertex{2},Vertex{3},Vertex{4}};
    Graph cycle = graph.GetCycle();
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Hello from Windows"<<std::endl;
    std::cout << "Hello from Ubuntu"<<std::endl;

    return 0;
}

