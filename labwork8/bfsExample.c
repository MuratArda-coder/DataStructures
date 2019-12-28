
/* Simple BFS and DFS Search */

#include <stdio.h>

#define NUM_OF_VERTICES 10

int dfs(int adj[][NUM_OF_VERTICES],int visited[],int start)
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
    return 0;
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
		//if(start==9)
		//	printf("10\t");
		//else
			printf("%d ",start+1); //change to 65 in case of alphabets

		for(i=0;i<NUM_OF_VERTICES;i++)
		{
			if(adj[start][i] && !visited[i])
			{
				queue[++rear]=i;
				visited[i]=1;
			}
		}
	}
}

int main()
{
	int visited[NUM_OF_VERTICES]={0};
	int i;
	int adj[NUM_OF_VERTICES][NUM_OF_VERTICES]={{0,0,1,0,0,0,0,0,0,1},
	{0,0,1,1,1,0,0,0,0,1},
	{0,1,0,0,1,0,1,0,0,0},
	{1,0,1,0,0,1,1,0,0,1},
	{0,0,0,0,0,0,1,1,0,0},
	{0,0,0,1,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,1,1,1},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,1,1,0}};

	bfs(adj,visited,0);
	for (i=0;i<NUM_OF_VERTICES;i++)
		visited[i] = 0;
	dfs(adj,visited,0);

	return 0;


}
