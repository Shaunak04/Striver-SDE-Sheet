class Solution 
{
public:
    // strictly increasing means duplicates need to be skipped in answer
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        int len = 0;
        set<int> st;
        for(auto i:nums) st.insert(i);
        vector<int> nums2;
        for(auto it=st.begin(); it!=st.end(); it++)
        {
            nums2.push_back(*it);
        }
        int n = nums.size();
        int m = nums2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==0 || j==0) dp[i][j] = 0;
                else if(nums[i-1] == nums2[j-1]) 
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};