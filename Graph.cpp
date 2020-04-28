//
// Created by stef4 on 4/18/2020.
//

#include "Graph.h"
#include <algorithm>



Graph Graph::GetCycle()
{
    vector<Vertex> usedVerticies;

    return FindCycle(usedVerticies,Vertex{1},Vertex{-1});
}

Graph Graph::FindCycle(vector<Vertex> usedVerticies, Vertex currVertex, Vertex parentVertex)
{
    usedVerticies.push_back(currVertex);

    for(auto vertex: Adj[currVertex])
    {
        if(find(usedVerticies.begin(),usedVerticies.end(),vertex)==usedVerticies.end())
        {
            Graph result = FindCycle(usedVerticies,vertex,currVertex);
            if(!result.Adj.empty())
            {
                return result;
            }
        }
        else if(vertex!=parentVertex)
        {
            vector<Vertex> cycle;
            cycle.insert(cycle.begin(),find(usedVerticies.begin(),usedVerticies.end(),vertex),usedVerticies.end());
            Graph cycleGraph;
            map<Vertex, vector<Vertex>> result;
            result[cycle[0]] = {cycle[1],cycle[cycle.size()-1]};
            result[cycle[cycle.size()-1]] = {cycle[0],cycle[cycle.size()-2]};
            for(int i = 1;i<cycle.size()-1;i++)
            {
                result[cycle[i]] = {cycle[i-1],cycle[i+1]};
            }
            cycleGraph.Adj = result;
            return cycleGraph;
        }
    }
    return Graph();
}

vector<Graph> Graph::GetSegments(Graph cycle)
{
    vector<Graph> result;
    vector<vector<Vertex>> allSegments;
    for(auto pair:cycle.Adj)
    {
        vector<Vertex> adjacentVeticies = cycle.Adj[pair.first];
           for(auto graphVertex:Adj[pair.first])
           {
               if(find(adjacentVeticies.begin(),adjacentVeticies.end(),graphVertex)==adjacentVeticies.end())
               {
                    vector<Vertex> usedVerticies;
                    usedVerticies.push_back(pair.first);
                    vector<Vertex> segment = FindSegment(cycle,graphVertex,usedVerticies);
                    sort(segment.begin(),segment.end());
                    if(find(allSegments.begin(),allSegments.end(),segment)==allSegments.end())
                    {
                        allSegments.push_back(segment);
                        int segmentSize = segment.size();
                        map<Vertex, vector<Vertex>> segmentMap;
                        segmentMap[segment[0]] = {segment[1]};
                        segmentMap[segment[segmentSize-1]] = {segment[segmentSize-2]};
                        for(int i = 1;i<segmentSize-1;i++)
                        {
                           segmentMap[segment[i]] = {segment[i-1],segment[i+1]};
                        }
                        Graph segmentGraph;
                        segmentGraph.Adj = segmentMap;
                        result.push_back(segmentGraph);
                    }
               }
           }
    }
    return result;
}

vector<Vertex> Graph::FindSegment(Graph cycle, Vertex currVertex, vector<Vertex> usedVerticies)
{
    vector<Vertex> result;
    usedVerticies.push_back(currVertex);
    if(cycle.Adj.count(currVertex)==0)
    {
        for(auto vertex:Adj[currVertex])
        {
            if(find(usedVerticies.begin(),usedVerticies.end(),vertex)==usedVerticies.end())
            {
                result = FindSegment(cycle,vertex,usedVerticies);
                return result;
            }
        }
    }
    else
    {
        return usedVerticies;
    }
}
