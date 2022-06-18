class Solution {
  public:
  
    bool checkCycle(int node, bool vis[], vector<int> adj[], int parent)
    {
        vis[node] = true;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(checkCycle(it, vis, adj, node)) return true;
            }
            else if(it!=parent) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
       bool vis[V];
       memset(vis, false, sizeof vis);

       for(int i=0; i<V; i++)
       {
           if(!vis[i])
           {
               if(checkCycle(i, vis, adj, -1)) return true;
           }
       }
       return false;
    }
};