#ifndef GraphL_H
#define GraphL_H

#include "nodedata.h"
#include <string>
#include <fstream> 
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// GraphL Class: Reads in data from a text file and creates a graph from the 
// data and then performs depth-first search on the created graph
//   Additional Functions:
//   -- Performs depth-first search on the graph
//   -- Prints out name of node with the edges of the node
//   -- Prints out the the depth-first search of the graph
// Implementation and assumptions:
//   -- reads in from a txt file where each line ends "0 0"
//   -- array length will not exceed 100 values
//---------------------------------------------------------------------------

const int MAXNODESB = 100; // global variable for array size

class GraphL {                            

public:
   GraphL();         // default constructor
   ~GraphL();        // destructor

   void buildGraph(ifstream &infile); // buildGraph: builds up graph node information and adjacency list of 
   // edges between each node reading from a data file. 

   void displayGraph(); //Displays each node information and edge in the graph 
	void depthFirstSearch(); // Makes a depth-first search and displays each node in depth-first order 
	// Some utility functions may be needed.


private:
   struct EdgeNode;      // forward reference for the compiler
   struct GraphNode {// structs used for simplicity, use classes if desired
      EdgeNode* edgeHead; // head of the list of edges - current node 
      NodeData* data;     // data information about each node - name 
      bool visited;      
   };

   struct EdgeNode {
      int adjGraphNode;  // subscript of the adjacent graph node - data collection
      EdgeNode* nextEdge; // next edge in the graph 
   };

   GraphNode arr[MAXNODESB]; // array of GraphNodes

   int size;                  // tracks the size of the array
   void dfsHelper(int n);     // helper for depth first search
   void insert(int n1, int n2);  // helper to insert the nodes into the array of GraphNodes
};
#endif 