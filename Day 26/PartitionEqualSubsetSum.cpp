class Solution 
{
public:   
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        sum/=2;
        int n = nums.size();
        bool dp[n+1][sum+1];
        memset(dp, false, sizeof dp);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<sum;j++)
            {
                if(i==0) dp[i][0] = true;
                if(j==0) dp[0][j] = false;
            }
        }
        dp[0][0] = true;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};