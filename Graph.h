//
// Created by stef4 on 4/18/2020.
//
#include <vector>
#include <map>


#ifndef PLANARITYTESTING_GRAPH_H
#define PLANARITYTESTING_GRAPH_H

using namespace std;

struct Vertex
{
    int number;

    bool Equals(Vertex vertex)
    {
        return number==vertex.number;
    }

    bool operator<(const Vertex& r)const
    {
        return number<r.number;
    }

    bool operator==(const Vertex& r)const
    {
        return number == r.number;
    }

    bool operator!=(const Vertex& r)const
    {
        return number != r.number;
    }
};



class Graph
{
public:
    //Cписок зв'язності графа
    map<Vertex,vector<Vertex>> Adj;
    Graph GetCycle();
    vector<Graph> GetSegments(Graph cycle);
private:
    Graph FindCycle(vector<Vertex> usedVerticies, Vertex currVertex, Vertex parentVertex);

    Graph FindSegment(Graph cycle, Vertex currVertex, vector<Vertex> usedVerticies);
};


#endif //PLANARITYTESTING_GRAPH_H
