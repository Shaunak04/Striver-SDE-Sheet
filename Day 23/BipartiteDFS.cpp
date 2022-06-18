class Solution {
public:
    bool bipartite(int node, vector<int> adj[], int color[])
    {
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                color[it] = 1-color[node];
                if(!bipartite(it, adj, color)) return false;
            }
            else if(color[it] == color[node]) return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[])
	{
	    int color[V];
	    memset(color, -1, sizeof color);
	    for(int i=0; i<V; i++)
	    {
	        if(color[i]==-1)
	        {
	            color[i] = 1;
	            if(!bipartite(i, adj, color)) return false;
	        }
	    }
	    return true;
	}
};