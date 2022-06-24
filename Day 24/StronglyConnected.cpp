/*
Step-1: TOPOSORT
Step-2: TRANSPOSE
Step-3: DFS on toposort's stack
*/

void toposort(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) 
{
    vis[node] = 1; 
    for(auto it: adj[node]) 
    {
        if(!vis[it]) 
        {
            toposort(it, st, vis, adj); 
        }
    }
    st.push(node); 
}
void dfs(int node, vector<int> &vis, vector<int> transpose[]) 
{
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) 
    {
        if(!vis[it]) 
        {
            dfs(it, vis, transpose); 
        }
    }
}

int main() 
{
	stack<int> st;
	vector<int> vis(n+1, 0); 
	for(int i=1; i<=n; i++) 
    {
	    if(!vis[i]) 
        {
	        toposort(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n+1]; 
	
	for(int i = 1;i<=n;i++) 
    {
	    vis[i] = 0; 
	    for(auto it: adj[i]) 
        {
	        transpose[it].push_back(i); 
	    }
	}
	
	while(!st.empty()) 
    {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) 
        {
	        cout << "SCC: "; 
	        dfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	return 0;
}