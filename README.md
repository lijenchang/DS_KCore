# Core Decomposition of Undirected and Unweighted Graphs
Given an undirected unweighted graph, number of vertices, and an integer k, this program uses BZ algorithm to compute the coreness for each vertex and outputs all vertices with coreness greater than or equal to k.
## Compilation
```
$ make
```
## Running
```
$ ./find_coreness <input_file_name> <number_of_vertices> <k>
```
Example:
```
$ ./find_coreness testcase.txt 82168 0
```
## Input File Format
If there are n vertices, vertex IDs are 0 ~ n-1. In the input file, each line consists of two integers u and v separated by a space, meaning that there exists an edge between u and v. 

Example:
```
0 1
0 2
0 3
0 4
1 2
1 3
1 4
2 3
2 4
3 4
```
## Output File Format
The output file is named "kcore.txt". In this file, each line consists of a vertex ID and its coreness, and vertex IDs are sorted in ascending order. 

Example:
```
0 4
1 4
2 4
3 4
4 4
```
## Testcase Information
An undirected unweighted graph with 82168 vertices and 2072442 edges
## References
W. Khaouid, M. Barsky, V. Srinivasan, and A. Thomo. K-Core Decomposition of Large Networks on a Single PC. Proceedings of the VLDB Endowment, 9(1): 13-23, 2015. 

V. Batagelj and M. Zaversnik. An O(m) Algorithm for Cores Decomposition of Networks. arXiv preprint cs/0310049, 2003. 
