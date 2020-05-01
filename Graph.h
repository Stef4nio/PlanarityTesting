//
// Created by stef4 on 4/18/2020.
//
#include <utility>
#include <vector>
#include <map>
#include <algorithm>


#ifndef PLANARITYTESTING_GRAPH_H
#define PLANARITYTESTING_GRAPH_H

using namespace std;

struct Vertex
{
    int number;

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

struct Segment
{
     vector<Vertex> SegmentVector;

     Segment(vector<Vertex> elements)
     {
         SegmentVector = std::move(elements);
     }

    bool operator==(const Segment& r)const
    {
        vector<Vertex> sortedLeftOperand = SegmentVector;
        vector<Vertex> sortedRightOperand = r.SegmentVector;
        sort(sortedLeftOperand.begin(), sortedLeftOperand.end());
        sort(sortedRightOperand.begin(),sortedRightOperand.end());
        return sortedLeftOperand==sortedRightOperand;
    }

    bool operator!=(const Segment& r)const
    {
        return !((*this)==r);
    }

    Vertex& operator[](int x)
    {
         return SegmentVector[x];
    }
};

class Graph
{
public:
    //Геттер списоку зв'язності графа
    map<Vertex,vector<Vertex>> Adj()
    {
        return AdjList;
    }

    Graph(map<Vertex,vector<Vertex>> adjList)
    {
        AdjList = std::move(adjList);
    }

    Graph()
    {
        AdjList = map<Vertex,vector<Vertex>>();
    }

    void Init()
    {
        Graph cycle = GetCycle();
        vector<Segment> segments = GetSegments(cycle);
        int x = 10;
    }
private:
    //Сам список зв'язності графа
    map<Vertex,vector<Vertex>> AdjList;
    //Масив граней графа
    vector<vector<Vertex>> planes;
    //Цикл, знайдений для гамма-алгоритму
    Graph FindCycle(vector<Vertex> usedVerticies, Vertex currVertex, Vertex parentVertex);
    Segment FindSegment(const Graph &cycle, Vertex currVertex, vector<Vertex> usedVerticies);
    Graph GetCycle();
    vector<Segment> GetSegments(Graph cycle);
};


#endif //PLANARITYTESTING_GRAPH_H
