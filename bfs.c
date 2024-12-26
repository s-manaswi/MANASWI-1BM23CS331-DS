#include<stdio.h>
#include<stdlib.h>
#define MAX 3
void bfs(int adj[][MAX],int visited[],int start)
{
    int queue[MAX],rear=-1,front=-1,i,k;
    for(k=0;k<MAX;k++){
        visited[k]=0;
    }
    queue[++rear]=start;
    ++front;
    visited[start]=1;
    while(rear>=front)
    {
        start=queue[front++];
        printf("%d->",start);
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]&&visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}


int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX],i,j;
    int choice,size;
    while(1){
        printf("\n 1. Enter values in graph ");
        printf("\n 2. BFS Traversal");
        printf("\n3.Exit");
        printf("\n \n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n Enter the adjacency matrix:");
                    for(i=0;i<MAX;i++){
                        for(j=0;j<MAX;j++){
                            scanf("%d",&adj[i][j]);
                        }
                    }
                    break;

            case 2: printf("BFS Traversal:");
                    bfs(adj,visited,0);
                    break;

            case 3: exit(0);
            default: printf("invalid choice");
    
        }
    }
}