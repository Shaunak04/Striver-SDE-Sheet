class Solution 
{
public:
    
    bool bipartiteBFS(int node, vector<vector<int>> graph, int color[])
    {
        queue<int> q; // queue for BFS
        q.push(node); // push current node in queue
        color[node] = 1; // mark current node as visited
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            for(auto it:graph[top]) // traverse all adjacent nodes of top element
            {
                if(color[it]==-1) // if not visited yet, push it to queue
                {
                    color[it] = 1-color[top];
                    q.push(it);
                }
                else if(color[it]==color[top]) return false;
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        int color[n];
        memset(color, -1, sizeof color);
        for(int i=0; i<n; i++)
        {
            if(color[i]==-1) // node not visited yet
            {
                if(!bipartiteBFS(i, graph, color)) // if coloring NOT possible, not bipartite so return FALSE
                {
                    return false;
                }
            }
        }
        return true;
    }
};