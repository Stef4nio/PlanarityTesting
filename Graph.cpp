//
// Created by stef4 on 4/18/2020.
//

#include "Graph.h"
#include <algorithm>



Graph Graph::GetCycle()
{
    vector<Vertex> usedVerticies;

    return FindCycle(usedVerticies,Vertex{3},Vertex{-1});
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
    for(auto pair:cycle.Adj)
    {
        vector<Vertex> adjacentVeticies = cycle.Adj[pair.first];
           for(auto graphVertex:Adj[pair.first])
           {
               if(find(adjacentVeticies.begin(),adjacentVeticies.end(),graphVertex)!=adjacentVeticies.end())
               {
                    //Create RECURSIVE DFS function to find segments
               }
           }
    }
}
