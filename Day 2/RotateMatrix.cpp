class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int i=0; i<(n+1)/2; i++)
        {
            for(int j=0; j<n/2; j++)
            {
                int temp = matrix[n-1-j][i]; // temp <- bottom left
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]; // bottom left <-  bottom right
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]; // bottom right <- top right
                matrix[j][n-1-i] = matrix[i][j]; // top right <- top left
                matrix[i][j] = temp; // top left <- temp
            }
        }
    }
};