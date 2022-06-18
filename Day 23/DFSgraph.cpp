#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
   void dfs(int node, int V, bool vis[], vector<int> ad[], vector<int>& ans)
   {
       vis[node] = true;
       ans.push_back(node);
       for(auto i:ad[node])
       {
            if(!vis[i])
            {
                dfs(i, V, vis, ad, ans);
            }
       }
   }
    vector<int> dfsOfGraph(int V, vector<int> ad[]) {
        bool vis[V];
        memset(vis, false, sizeof vis);
        vector<int> ans;
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs(i, V, vis, ad, ans);
            }
        }
        return ans;
    }
};