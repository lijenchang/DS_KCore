#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Graph.h"

using namespace std;

Graph::Graph( const int n ): V( n )
{
    adjList.resize( n );
    degree.resize( n, 0 );
}

Graph::~Graph()
{

}

void Graph::AddEdge( const int u, const int v )
{
    if ( u == v ) return;
    adjList[u].push_back( v );
    adjList[v].push_back( u );
    degree[u]++;
    degree[v]++;
}

/* Batagelj and Zaversnik Algorithm */
void Graph::KCore( const int k )
{
    vector<int> vertex( V, 0 );  // vertices sorted by their degrees in increasing order
    vector<int> deg( V, 0 );
    vector<int> bin( V, 0 );     // contains, for each possible degree, the position of the first vertex of that degree in array "vertex"
    vector<int> pos( V, 0 );     // stores positions of vertices in array "vertex"

    /* Initialization */
    for ( int i = 0; i < V; ++i ) {
        deg[i] = degree[i];
        bin[deg[i]]++;
    }
    int start = 0;
    for ( int i = 0; i < V; ++i ) {
        int num = bin[i];
        bin[i] = start;
        start += num;
    }
    // Bin sort vertices by their degree
    for ( int i = 0; i < V; ++i ) {
        pos[i] = bin[deg[i]];
        vertex[pos[i]] = i;
        bin[deg[i]]++;
    }
    // Recover bin[]
    for ( int i = V - 1; i >= 1; --i ) bin[i] = bin[i - 1];
    bin[0] = 0;
    
    /* Main Algorithm */
    for ( int i = 0; i < V; ++i ) {
        int v = vertex[i];
        for ( auto u : adjList[v] ) {
            if ( deg[u] > deg[v] ) {
                int du = deg[u], pu = pos[u];
                int pw = bin[du];
                int w = vertex[pw];
                if ( u != w ) {
                    pos[u] = pw;
                    pos[w] = pu;
                    vertex[pu] = w;
                    vertex[pw] = u;
                }
                bin[du]++;
                deg[u]--;
            }
        }
    }
    
    /* Output the Result */
    ofstream outputFile( "kcore.txt" );
    if ( !outputFile ) {
        cerr << "Output file could not be opened!" << endl;
        exit( EXIT_FAILURE );
    }
    for ( int i = 0; i < V; ++i ) {
        if ( deg[i] < k ) continue;
        outputFile << i << ' ' << deg[i] << '\n';
    }
    outputFile.close();
}
