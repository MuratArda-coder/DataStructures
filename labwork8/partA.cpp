#include <stdio.h>
#include <iostream>
#define NUM_OF_VERTICES 8
using namespace std;

class Graph{
	public: 
	int adjMatrix[NUM_OF_VERTICES][NUM_OF_VERTICES];

	Graph(int a[][NUM_OF_VERTICES]) //copy matrix a to adjmatrix
	{
		for(int i=0;i<NUM_OF_VERTICES;i++)
		{
			for(int j=0;j<NUM_OF_VERTICES;j++)
			{
				adjMatrix[i][j]=a[i][j];
			}
		}
	}
	
	
	int findInDegree(int c);  // find indegree of index c

	int findOutDegree(int c); // find outdegree of index c
 
	int findNumberOfEdges(); // find number of edges in the graph
	
	void displayInfo(); //display indegree and outdegree of all vertices. Also print total number of edges. 
	

};

int main()
{
	int a[NUM_OF_VERTICES][NUM_OF_VERTICES]={{0,1,1,0,0,0,0,0},
	{1,0,0,1,1,0,0,0},
	{1,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0},
	{0,1,0,0,0,0,1,1},
	{0,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,0,1,0,0,0}};

	Graph g(a);
	g.displayInfo();
	


}
