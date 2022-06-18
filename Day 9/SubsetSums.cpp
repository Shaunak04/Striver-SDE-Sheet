class Solution
{
public:
    
    void helper(int N, vector<int>& ans, int sum, vector<int>& arr)
    {
        if(N==0)
        {
            ans.push_back(sum);
            return;
        }
        helper(N-1, ans, sum, arr);
        helper(N-1, ans, sum+arr[N-1], arr);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        helper(N, ans, 0, arr);
        return ans;
    }
};