class Solution 
{
  public:

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        queue<int> q;
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        
        for(int i=0; i<indegree.size(); i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return cnt!=V;
    }
};