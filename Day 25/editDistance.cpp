class Solution 
{
public:
    int dp[501][501]; // memoization table
    
    int editDis(string& word1, string& word2, int n1, int n2)
    {
        if(n1 == 0) // if first word ended, return second index
            return n2;
        
        if(n2 == 0) // if second index ends, return first index
            return n1;
        
        if(dp[n1][n2] !=-1) // if problem has been precomputed, return result
        {
            return dp[n1][n2];
        }
        
        if(word1[n1-1] == word2[n2-1]) // if both characters are same at n1 and n2 indices, return prev indices subproblem
        {
            return dp[n1][n2] = editDis(word1, word2, n1-1, n2-1);
        }
            
        // else return 1+min of 3 operations
        return dp[n1][n2]=  1+min({editDis(word1, word2, n1, n2-1),
                  editDis(word1, word2, n1-1, n2),
                  editDis(word1, word2, n1-1, n2-1)});
    }
    
    int minDistance(string word1, string word2) 
    {
        int n1 = word1.size();
        int n2 = word2.size();
        memset(dp, -1, sizeof dp);
        dp[n1][n2] = editDis(word1, word2, n1, n2);
        return dp[n1][n2];
    }
};