class Solution
{
	public:
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int source) 
    {
        vector<int> distTo(V, 1e8);
        distTo[source] = 0;
        for(int i=0; i<V; i++)
        {
            // relax N-1 edges
            for(auto i:adj)
            {
                int u = i[0];
                int v = i[1];
                int w = i[2];
                if(distTo[u] + w < distTo[v])
                {
                    distTo[v] = distTo[u] + w; 
                }
            }
        }
        for(int i=0; i<V; i++)
        {
            for(auto i:adj)
            {
                int u = i[0];
                int v = i[1];
                int w = i[2];
                if(distTo[u] + w < distTo[v])
                {
                    distTo[v] = 1e8;
                }
            }
        }
        return distTo;
    }
};