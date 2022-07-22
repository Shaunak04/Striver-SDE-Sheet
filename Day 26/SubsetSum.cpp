    int coinChange(vector<int>& coins, int amount) 
    {   
        int n = coins.size();
        int dp[n+1][amount+1];
         
        for(int i=0; i<=amount; i++)
        {
            dp[0][i] = INT_MAX - 1;
        }
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                if(coins[i-1] <= j)
                {
                    // either skip the current coin or choose the current coin and subtract the coin value from   target
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j]; // skip current coin
                }
            }
        }
        
        return (dp[n][amount]==INT_MAX || dp[n][amount]==INT_MAX-1) ? -1 : dp[n][amount];
    }