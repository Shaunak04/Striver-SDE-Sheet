class Solution
{
	public:

	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int> indeg(n, 0);
	    for(int i=0; i<n; i++)
	    {
	        for(auto j:adj[i])
	        {
	            indeg[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0; i<indeg.size(); i++)
	    {
	        if(indeg[i]==0) q.push(i);
	    }

	    vector<int> ans;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it:adj[node])
	        {
	            indeg[it]--;
	            if(indeg[it]==0) q.push(it);
	        }
	    }
	    return ans;
	}
};