class Solution 
{
public:
    
    bool checkCycle(int node, vector<vector<int>>& graph, bool vis[], bool dfsvis[])
    {
        vis[node] = true;
        dfsvis[node] = true;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(checkCycle(it, graph, vis, dfsvis)) return true;
            }
            else if(dfsvis[it]==true) return true;
        }
        dfsvis[node] = false;
        return false;
    }
    
    bool cycleInGraph(int V, vector<vector<int>>& adj) 
    {
        bool vis[V];
        bool dfsvis[V];
        memset(vis, false, sizeof vis);
        memset(dfsvis, false, sizeof dfsvis);
        
        vector<vector<int>> graph(V);
        for(auto &e:adj)
        {
            graph[e[0]].push_back(e[1]);
        }
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i, graph, vis, dfsvis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};