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

int Graph::findInDegree(int c)  // find indegree of index c
{
	int count=0;
	for(int i=0;i<NUM_OF_VERTICES;i++)
	{
		count+=adjMatrix[i][c];
	}
	return count;
}

int Graph::findOutDegree(int c) // find outdegree of index c
{
	int count=0;
	for(int i=0;i<NUM_OF_VERTICES;i++)
	{
		count+=adjMatrix[c][i];
	}
	return count;
}
 
int Graph::findNumberOfEdges() // find number of edges in the graph
{
	int count=0;
	for(int i=0;i<NUM_OF_VERTICES;i++)
	{
		for(int j=0;j<NUM_OF_VERTICES;j++)
			count+=adjMatrix[i][j];
	}
	return count/2;
}
	
void Graph::displayInfo() //display indegree and outdegree of all vertices. Also print total number of edges. 
{
	cout<<"vertex\tindegree\toutdegree\n";
	for(int i=0;i<NUM_OF_VERTICES;i++)
	{
		cout<<i<<"\t"<<findInDegree(i)<<"\t"<<findOutDegree(i)<<endl;
	}
	cout<<"total number of edges: "<<findNumberOfEdges()<<endl;
}

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
