class Solution
{
	public:
	void topo(int node, bool vis[], vector<int> adj[], stack<int>& st)
	{
	    vis[node] = true;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            topo(it, vis, adj, st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    stack<int> st;
	    bool vis[n];
	    memset(vis, false, sizeof vis);
	    for(int i=0; i<n; i++)
	    {
	        if(!vis[i])
	        {
	            topo(i, vis, adj, st);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};