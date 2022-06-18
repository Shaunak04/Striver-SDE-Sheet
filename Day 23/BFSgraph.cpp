#include <bits/stdc++.h>
using namespace std;

class Solution 
{
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<bool> visited;
        vector<int> ans;
        visited.resize(V,false);
        queue<int> q;
        q.push(0);

        while(!q.empty())
        {
            int s = q.front();
            ans.push_back(s);
            q.pop();
    
            for (auto adjecent: adj[s])
            {
                if (!visited[adjecent])
                {
                    visited[adjecent] = true;
                    q.push(adjecent);
                }
            }
        }
        return ans;
    }
};