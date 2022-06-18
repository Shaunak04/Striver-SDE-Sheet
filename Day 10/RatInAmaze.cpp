#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> ans;
    bool isSafe(int nx, int ny, vector<vector<int>>& m, int n)
    {
        if(nx>=0 && ny>=0 && nx<n && ny<n && m[nx][ny]==1) return true;
        return false;
    }
    
    void solve(int row, int col, vector<vector<int>>& m, int n, string path)
    {
        if(row==n-1 && col==n-1)
        {
            ans.push_back(path);
            return;
        }
        // up
        string d = "URDL";
        int dir[5] = {-1, 0, 1, 0, -1};
        for(int i=0; i<4; i++)
        {
            int nx = row + dir[i];
            int ny = col + dir[i+1];
            if(isSafe(nx, ny, m, n))
            {
                m[nx][ny] = 2;
                solve(nx, ny, m, n, path+d[i]);
                m[nx][ny] = 1;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        if(m[0][0]==0) return {};
        m[0][0] = 2;
        solve(0,0, m, n, "");
        return ans;
    }
};