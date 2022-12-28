#include "graphm.h"

//----------------------------------------------------------------------------
// Constructor
// Constructor: Initializes all the necessary values in the arrays
GraphM::GraphM()
{
	size = 0; 
	for (int i = 0; i < MAXNODES; i++)
	{
		for (int j = 0; j < MAXNODES; j++)
		{
			T[i][j].visited = false;
			T[i][j].dist = INFINITY; 
			T[i][j].path = 0; 
		}
	}

	for (int k = 0; k < MAXNODES; k++)
	{
		for (int h = 0; h < MAXNODES; h++)
		{
			C[k][h] = INFINITY; 
		}
	}
}

// buildGraph: builds up graph node information and adjacency matrix of edges 
// between each node reading from a data file.
void GraphM::buildGraph(ifstream& infile) 
{
	string name; 
	int num = 0;
	while (!infile.eof()) {
		infile >> num;
		size = num; 
		int index = 1; 
		getline(infile, name);
		while (getline(infile, name) && index != num + 1)
		{
			NodeData ptr(name);
			data[index] = ptr;
			index++; 
		}
		int a, b, c;
		while((a != 0 && b != 0 && c != 0) && !infile.eof())
		{
			infile >> a >> b >> c;
			C[a][b] = c;
		}
		break; 
	}	
}; 

//----------------------------------------------------------------------------
// insertEdge()
// insertEdge(): adds an edge between twp given nodes
void GraphM::insertEdge(int n1, int n2, int weight) 
{
	C[n1][n2] = weight;

};

//----------------------------------------------------------------------------
// removeEdge()
// removeEdge(): removes an edge between two given nodes
void GraphM::removeEdge(int n1, int n2, int weight) 
{
	C[n1][n2] = INFINITY; 
}; 

//----------------------------------------------------------------------------
// findShortestPath()
// findShortestPath(): Finds the shortest path from all nodes in a graph
void GraphM::findShortestPath() 
{
	for (int k = 1; k < size + 1; k++)
	{
		int ans = 0; 
		T[k][k].dist = 0;
		C[k][k] = 0; 
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q; 
		for (int i = 1; i < size + 1; i++)
		{
			pair<int, int> pr(C[k][i], i);
			q.push(pr);	
		} 
		while(!q.empty())
		{
			int u = q.top().second;
			q.pop();
			for (int j = 1; j < size + 1; j++) 
			{
				if (C[u][j] != INFINITY)
				{
					int weight = C[u][j];
					if (T[k][j].dist > T[k][u].dist + weight)
					{
						if (T[k][u].dist != INFINITY)
						{
							T[k][j].dist = T[k][u].dist + weight;	
							T[k][j].path = u;
							pathConverter(k, j, u); 
						}
						pair<int, int> pr(T[k][j].dist, j);
						q.push(pr);
						T[k][j].visited = true;
					}
				}
			}
		}
	}
};

//----------------------------------------------------------------------------
// displayAll()
// displayAll(): Prints out all nodes in the graph and the shortest path from each 
void GraphM::displayAll() const 
{
	cout << "Description         From node  To node  Dijkstra's  Path    " << endl;
	for (int i = 1; i < size + 1; i++)
	{
		cout << data[i] << endl;
		for (int j = 1; j < size + 1; j++)
		{
			if (i != j)
			{
				cout << "\t\t\t" << i << "\t" << j << "\t"; 
				if (T[i][j].dist == INFINITY)
				{
					cout << "---" << "\t\t" << endl;
				}
				else 
				{
					cout << T[i][j].dist << "\t    " << i << " ";
					{
						for (int x = 1; x < size + 1; x++)
						{
							if ((pathArr[i][j][x] != 0) && (pathArr[i][j][x] != i))
							{
								cout << pathArr[i][j][x] << " ";
							}
						}
					}
					cout << j << " " << endl;
				}
			}	
		} 
	}
}; 

//----------------------------------------------------------------------------
// display()
// display(): Prints out a singular node data
void GraphM::display(int a, int b) const
{
	cout << "Display Function for Node " << a << " to Node " << b << endl; 
	cout << a << "\t" << b << "\t";
	if (T[a][b].dist == INFINITY)
	{
		cout << "---" << endl; 
		
	}
	else
	{
		cout << T[a][b].dist << "\t" << T[a][b].path << endl;
		cout << data[T[a][b].path] << endl;
	}	 
}; 

//----------------------------------------------------------------------------
// pathConverter()
// pathConverter(): Adds path into a matrix of arrays for a specific node
void GraphM::pathConverter(int vertex, int ansNum, int n)
{
	pathArr[vertex][ansNum][n] = n; 
}

