// KADANE'S ALGORITHM

class Solution 
{
public:
    int maxSubArray(vector<int>& arr) 
    {
        int curr_sum = arr[0];
        int max_sum = curr_sum;
        for(int i=1;i<arr.size();i++)
        {
            curr_sum = max(curr_sum + arr[i], arr[i]);
            max_sum = max(curr_sum, max_sum);
        }
        return max_sum;
    }
};