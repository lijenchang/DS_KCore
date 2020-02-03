#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Graph.h"

using namespace std;

int main( int argc, char* argv[] )
{
    int n = stoi( argv[2] );  // number of vertices
    int k = stoi( argv[3] );
    
    Graph g( n );
    
    // Open the input file
    ifstream inputFile( argv[1] );
    if ( !inputFile ) {
        cerr << "Input file could not be opened!" << endl;
        exit( EXIT_FAILURE );
    }

    int u, v;
    while ( inputFile >> u >> v ) g.AddEdge( u, v );

    inputFile.close();

    g.KCore( k );
}
