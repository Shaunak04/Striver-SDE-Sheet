class Solution {
  public:
  
    bool checkCycle(int s, bool vis[], vector<int> adj[], int n)
    {
        queue<pair<int, int>> q;
        vis[s] = true;
        q.push({s, -1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = true;
                    q.push({it, node});
                }
                else if(parent!=it)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
       bool vis[V];
       memset(vis, false, sizeof vis);

       for(int i=0; i<V; i++)
       {
           if(!vis[i])
           {
               if(checkCycle(i, vis, adj, V)) return true;
           }
       }
       return false;
    }
};