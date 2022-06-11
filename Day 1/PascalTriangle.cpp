class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        if(n==1)
        {
            return {{1}};
        }
        else if(n==2)
        {
            return {{1},{1,1}};
        }
        else
        {
            vector<vector<int>> pas = {{1}, {1,1}};
            for(int i=2; i<n; i++)
            {
                vector<int> temp;
                temp.push_back(1);
                for(int j=1; j<i; j++)
                {
                    temp.push_back(pas[i-1][j] + pas[i-1][j-1]);
                }
                temp.push_back(1);
                pas.push_back(temp);
            }
            return pas;
        }
    }
};