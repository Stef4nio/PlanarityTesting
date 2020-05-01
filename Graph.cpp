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

    for(auto vertex: AdjList[currVertex])
    {
        if(find(usedVerticies.begin(),usedVerticies.end(),vertex)==usedVerticies.end())
        {
            Graph result = FindCycle(usedVerticies,vertex,currVertex);
            if(!result.AdjList.empty())
            {
                return result;
            }
        }
        else if(vertex!=parentVertex)
        {
            vector<Vertex> cycleVector;
            cycleVector.insert(cycleVector.begin(), find(usedVerticies.begin(), usedVerticies.end(), vertex), usedVerticies.end());
            //Додати внутрішню грань циклу
            planes.push_back(cycleVector);
            //Додати зовнішню грань циклу
            planes.push_back(cycleVector);
            map<Vertex, vector<Vertex>> result;
            result[cycleVector[0]] = {cycleVector[1],cycleVector[cycleVector.size()-1]};
            result[cycleVector[cycleVector.size()-1]] = {cycleVector[0],cycleVector[cycleVector.size()-2]};
            for(int i = 1;i<cycleVector.size()-1;i++)
            {
                result[cycleVector[i]] = {cycleVector[i-1],cycleVector[i+1]};
            }
            return result;
        }
    }
    return Graph();
}

vector<Segment> Graph::GetSegments(Graph cycle)
{
    using namespace std;
    vector<Segment> allSegments;
    for(auto const& pair:cycle.AdjList)
    {
           for(auto graphVertex:AdjList[pair.first])
           {
               if(cycle.AdjList.count(graphVertex)==0)
               {
                    vector<Vertex> usedVerticies;
                    usedVerticies.push_back(pair.first);
                    Segment segment = FindSegment(cycle,graphVertex,usedVerticies);
                    if(find(allSegments.begin(),allSegments.end(),segment)==allSegments.end())
                    {
                        allSegments.push_back(segment);
                        //Segment to graph algorythm
                        /*int segmentSize = segment.SegmentVector.size();
                        map<Vertex, vector<Vertex>> segmentMap;
                        segmentMap[segment[0]] = {segment[1]};
                        segmentMap[segment[segmentSize-1]] = {segment[segmentSize-2]};
                        for(int i = 1;i<segmentSize-1;i++)
                        {
                           segmentMap[segment[i]] = {segment[i-1],segment[i+1]};
                        }*/
                    }
               }
           }
    }
    return allSegments;
}

Segment Graph::FindSegment(const Graph &cycle, Vertex currVertex, vector<Vertex> usedVerticies)
{
    usedVerticies.push_back(currVertex);
    if(cycle.AdjList.count(currVertex)==0)
    {
        for(auto vertex:AdjList[currVertex])
        {
            if(find(usedVerticies.begin(),usedVerticies.end(),vertex)==usedVerticies.end())
            {
                Segment result = FindSegment(cycle,vertex,usedVerticies);
                return result;
            }
        }
    }
    else
    {
        return Segment(usedVerticies);
    }
}
