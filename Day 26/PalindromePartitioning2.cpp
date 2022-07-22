int dp[502][502];
bool isPalindrome(string &s, int i, int j)
{
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve (string &s, int i, int j)
{    
    if(i>=j or isPalindrome(s, i, j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        if(isPalindrome(s, i, k))
        {                         
            int temp = solve(s, k+1, j) + 1;
            ans = min (ans, temp);
        }
    }
    return dp[i][j] = ans;
}

int Solution::minCut(string s) 
{
    int n = s.length();
    memset(dp, -1, sizeof dp);   
    return solve(s, 0, n-1);   
}