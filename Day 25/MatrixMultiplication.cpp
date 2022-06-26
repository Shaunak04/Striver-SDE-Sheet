class Solution
{
public:
   int dp[101][101];
   
   int solve(int arr[],int i,int j)
   {
       if(i>=j)
       {
           return 0;
       }
       if(dp[i][j]!=-1)
       {
           return dp[i][j];
       }
       int operations = INT_MAX;
       for(int k=i; k<j; k++)
       {
           int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
           operations = min(operations, temp);
       }
       return dp[i][j] = operations;
   }
   
   int matrixMultiplication(int n, int arr[])
   {
       for(int i=0; i<101; i++)
       {
           for(int j=0; j<101; j++)
           {
               dp[i][j] = -1;
           }
       }
       return solve(arr,1,n-1);
   }
};