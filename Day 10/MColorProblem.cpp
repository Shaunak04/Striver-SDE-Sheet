#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int tryColor, int n)
{
    for(int i=0; i<101; i++)
    {
        if(graph[node][i])
        {
            if(color[i]==tryColor) return false;
        }
    }
    return true;
}

bool colorNode(bool graph[101][101], int node, int color[], int n, int m)
{
    if(node==n)
    {
        return true;
    }
    
    for(int i=1; i<=m; i++)
    {
        if(isSafe(node, color, graph, i, n))
        {
            color[node] = i;
            if(colorNode(graph, node+1, color, n, m)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) 
{
    int color[n];
    memset(color, 0, sizeof color);
    return colorNode(graph, 0, color, n, m);
}