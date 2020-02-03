#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
public:
    Graph( const int n );
    ~Graph();
    void AddEdge( const int u, const int v );
    void KCore( const int k );
private:
    std::vector<std::vector<int>> adjList;
    std::vector<int> degree;
    int V;
};

#endif // GRAPH_H
