#ifndef GraphM_H
#define GraphM_H

#include "nodedata.h"
#include <queue>
#include <string>
#include <iterator> 
#include <limits> // to get a number similar to infinity
#include <fstream> 
#include <iostream>
using namespace std;


//---------------------------------------------------------------------------
// GraphM Class: Reads in data from a file and creates a directed graph
//   Additional Functions:
//   -- Find the shortest path to all nodes via Dijkstra's Algorithm
//   -- Can add or delete nodes to the graph
//   -- Prints out Dijkstra's Algorithm for each node with the name 
//      of the node, and the shortest path
//   -- Prints out the Dijkstra's Algorithm  with the path and name of the 
//      nodes for an individual node
// Implementation and assumptions:
//   -- reads in from a txt file where each line ends "0 0 0"
//   -- array length will not exceed 100 values
//---------------------------------------------------------------------------

const int MAXNODES = 100; // global variable for array size
const int INFINITY = numeric_limits<int>::max(); // global variable for max int value 

class GraphM {                            

public:
    GraphM(); // The data member T is initialized to set all dist to infinity, sets all visited to false, 
              // and sets all path to 0.

    void buildGraph(ifstream& infile); // buildGraph: builds up graph node information and adjacency matrix of edges 
                // between each node reading from a data file.

    void insertEdge(int n1, int n2, int weight); // insert an edge into graph between two given nodes
    void removeEdge(int n1, int n2, int weight); //remove an edge between two given nodes
    

    void findShortestPath(); // find the shortest path between every node to every other node in the graph, 
    ///i.e., TableType T is updated with shortest path information
    void displayAll() const; // uses couts to demonstrate that the algorithm works properly. 
    void display(int a, int b) const; // uses couts to show Dijkstra's algorithm for one specific node

private:
    struct TableType {
        bool visited;          // whether node has been visited
        int dist;              // shortest distance from source known so far
        int path;              // previous node in path of min dist
    };

    NodeData data[MAXNODES];              // data for graph nodes 
    int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix
    int size;                             // number of nodes in the graph
    TableType T[MAXNODES][MAXNODES];      // stores visited, distance, path

    void pathConverter(int vertex, int ansNum, int n); 
    int pathArr[MAXNODES][MAXNODES][MAXNODES];  

};
#endif 
