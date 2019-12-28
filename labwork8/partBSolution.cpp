#include <stdio.h>
#include <iostream>
#include <stack>
#define NUM_OF_VERTICES 8
using namespace std;

class Graph{
	public:
	int adjMatrix[NUM_OF_VERTICES][NUM_OF_VERTICES];

	Graph(int a[][NUM_OF_VERTICES])
	{
		for(int i=0;i<NUM_OF_VERTICES;i++)
		{
			for(int j=0;j<NUM_OF_VERTICES;j++)
			{
				adjMatrix[i][j]=a[i][j];
			}
		}
	}
};



void dfs(int adj[][NUM_OF_VERTICES],int visited[],int start)
{
    int stack[NUM_OF_VERTICES];
    int top=-1,i;

    printf("\n DFS Order-> %d",start);
    visited[start]=1;
    stack[++top]=start;
    while(top!=-1)
    {
                  start=stack[top];
                  for(i=0;i<NUM_OF_VERTICES;i++)
                  {
                                    if(adj[start][i]&&visited[i]==0)
                                    {
                                                                   stack[++top]=i;
                                                                   printf(" %d",i);
                                                                   visited[i]=1;
                                                                   break;
                                    }
                  }

                  if(i==NUM_OF_VERTICES)
                          top--;
    }    
    cout << endl;	
}


void bfs(int adj[][NUM_OF_VERTICES],int visited[],int start)
{
	int queue[NUM_OF_VERTICES],rear=-1,front=-1,i;
	queue[++rear]=start;
	visited[start]=1;
	printf("\n BFS Order-> ");
	while(rear != front)
	{
		start = queue[++front];		
		printf("%d ",start); //change to 65 in case of alphabets

		for(i=0;i<NUM_OF_VERTICES;i++)
		{
			if(adj[start][i] && !visited[i])
			{
				queue[++rear]=i;
				visited[i]=1;
			}
		}
	}
	cout << endl;
}


struct myPair
{
	int parent;
	int vertex;
};


void shortestPathWithBfs(int adj[][NUM_OF_VERTICES],int visited[],int start, int end)
{
	struct myPair history[NUM_OF_VERTICES];
	int historySize=0;
	int queue[NUM_OF_VERTICES],rear=-1,front=-1,i;
	queue[++rear]=start;
	visited[start]=1;
	printf("\n shortest path-> ");
	history[historySize].parent=-1;
	history[historySize++].vertex=start;
	while(rear != front)
	{
		start = queue[++front];		
	
		for(i=0;i<NUM_OF_VERTICES;i++)
		{
			if(adj[start][i] && !visited[i])
			{
				queue[++rear]=i;
				visited[i]=1;
				history[historySize].parent=start;
				history[historySize++].vertex=i;
				if(i==end)
					break;
			}
		}
		if(i!=NUM_OF_VERTICES)
			break;
	}
	stack<int> reverse;
	int current = end;
	for(int i=historySize-1; i!=-1; i--)
	{
		if(current == history[i].vertex){
			reverse.push(history[i].vertex);
			current = history[i].parent;
		}
	}
	while(!reverse.empty()){
		cout<<reverse.top()<<" ";
		reverse.pop();
	}
		
	
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
	int visited[NUM_OF_VERTICES];
	
	// call bfs and dfs functions here properly
	for(int i=0;i<NUM_OF_VERTICES;i++)
		visited[i]=0;
	bfs(a,visited,1);


	//call shortestPath function here properly
	for(int i=0;i<NUM_OF_VERTICES;i++)
		visited[i]=0;
	dfs(a,visited,1);

	for(int i=0;i<NUM_OF_VERTICES;i++)
		visited[i]=0;
	shortestPathWithBfs(a,visited,1,5);
	
}
