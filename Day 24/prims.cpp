class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int N, vector<vector<int>> graph[])
    {
        int parent[N]; 
        int key[N]; 
        bool mstSet[N]; 
        for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    
        key[0] = 0; 
        parent[0] = -1; 
        pq.push({0, 0});
    
        while(!pq.empty())
        { 
            int u = pq.top().second; 
            pq.pop(); 
            
            mstSet[u] = true; 
            
            for (auto it : graph[u]) 
            {
                int v = it[0];
                int weight = it[1];
                if (mstSet[v] == false && weight < key[v]) 
                {
                    parent[v] = u;
    	            key[v] = weight; 
                    pq.push({key[v], v});    
                }
            }
        }
        int ans = 0;
        for(auto i:key)
        {
            ans+=i;
        }
        return ans;
    }
};