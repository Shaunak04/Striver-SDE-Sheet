class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int recur(int e, int f)
    {
        if(e==1 || f==0 || f==1) return f;
        if(e<=0) return 0;
        if(dp[e][f]!=-1) return dp[e][f];
        int mn = INT_MAX;
        for(int k=1; k<f; k++)
        {
            int temp = max(recur(e-1, k-1), recur(e, f-k))+1;
            mn = min(mn, temp);
        }
        return dp[e][f] = mn;
    }
    int eggDrop(int e, int f) 
    {
        if(e==1 || f==0 || f==1) return f;
        memset(dp, -1, sizeof dp);
        return recur(e, f);
    }
};