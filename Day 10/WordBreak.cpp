class Solution 
{
public:
    int dp[1001];
    
    bool helper(unordered_map<string, int>& mp, string &s, int idx)
    {
		if(idx >= s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        string temp ="";
        for(int i=idx; i<s.size(); i++)
        {
            temp.push_back(s[i]);
            if(mp.find(temp)!=mp.end())
            {
                bool take = helper(mp, s, i+1);
                if(take) return dp[idx]=true;
            }
        }
        return dp[idx] = false; 
    }
    
    
    bool wordBreak(string &s, vector<string>& wordDict)
    {
        unordered_map<string, int> mp;
        for(auto x:wordDict)
        {
            mp[x]++;
        }
        memset(dp, -1, sizeof dp);
        return helper(mp, s, 0);
    }
};