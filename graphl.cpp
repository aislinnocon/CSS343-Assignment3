#include "graphl.h"

//----------------------------------------------------------------------------
// Constructor
// Constructor: Initializes values in the array 
GraphL::GraphL()
{
	for (int i = 0; i < MAXNODESB; i++)
	{
		arr[i] = GraphNode(); 
		arr[i].data = nullptr;
		arr[i].edgeHead = nullptr; 
	}
}

//----------------------------------------------------------------------------
// Destructor
// Destructor: Deletes memory once GraphL is complete
GraphL::~GraphL()
{  
}

//----------------------------------------------------------------------------
// buildGraph()
// buildGraph(): Builds the graph from a read in text file 
void GraphL::buildGraph(ifstream &infile)
{
    string name; 
	int num = 0;
	while (!infile.eof()) {
		infile >> num;
		size = num; 
		int index = 1;
        int a, b; 
		getline(infile, name);
		while (getline(infile, name) && index != num + 1)
		{
			NodeData* ptr = new NodeData(name); 
			arr[index].data = ptr;
			index++; 
            if (index == num + 1)
            {
                infile >> a >> b;
				insert(a, b); 
            }
		}
		infile >> a >> b;
		if (!infile.eof())
		{
			insert(a, b); 
		}
		while((a != 0 || b != 0) && !infile.eof())
		{
			infile >> a >> b;
			insert(a, b);
		}
		break; 
    }
}

//----------------------------------------------------------------------------
// insert()
// insert(): Inserts a connected node into the array 
void GraphL::insert(int n1, int n2)
{
	if (n1 != 0 || n2 != 0)
	{
    	EdgeNode* temp = new EdgeNode();
    	temp->adjGraphNode = n2;
    	temp->nextEdge = arr[n1].edgeHead;
    	arr[n1].edgeHead = temp;
	}
}

//----------------------------------------------------------------------------
// displayGraph()
// displayGraph(): Displays the node names, and which nodes there is a connection to
void GraphL::displayGraph()
{
	cout << endl; 
	cout << "Graph:" << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << "Node " << i << "\t\t" << *arr[i].data << endl;
		EdgeNode* temp = arr[i].edgeHead;
		while (temp != nullptr)
		{
			cout << i << " ";
			cout << temp->adjGraphNode << endl; 
			temp = temp->nextEdge; 
		} 
	}
}

//----------------------------------------------------------------------------
// depthFirstSearch()
// depthFirstSearch(): Finds the depth of all nodes in the graph
void GraphL::depthFirstSearch() 
{
	for (int i = 1; i <= size; i++)
	{
		arr[i].visited = false; 
	}
	cout << "Depth First Search" << endl;
	for (int j = 1; j <= size; j++)
	{
		if (arr[j].edgeHead != nullptr && !arr[j].visited) 
		{
			dfsHelper(j);	
		}	
	}
	cout << endl; 
}

//----------------------------------------------------------------------------
// dfsHelper()
// dfsHelper(): Helper to find the depth of one node
void GraphL::dfsHelper(int n)
{
	arr[n].visited = true;
	cout << n << " "; 
	EdgeNode* temp = arr[n].edgeHead;
	while(temp != nullptr)
	{
		if (!arr[temp->adjGraphNode].visited )
		{ 
			dfsHelper(temp->adjGraphNode); 
		}
		temp = temp->nextEdge; 
	}
}




