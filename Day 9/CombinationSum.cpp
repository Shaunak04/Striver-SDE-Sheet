class Solution 
{
public:
    vector<vector<int>> answer;
    void findComb(int index, int n,vector<int>& current, vector<int>& nums, int remaining)
    {
        if(remaining < 0) // remaining sum <0 = > invalid combination formed
        {
            return;
        }
        else if(remaining==0) // valid combination formed, push in answer
        {
            answer.push_back(current);
        }
        else
        {
            for(int i=index; i<n; i++) // from current index till end, perform give and take
            {
                current.push_back(nums[i]); // give
                findComb(i, n, current, nums, remaining - nums[i]);
                current.pop_back(); // take
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<int> current;
        int n = nums.size();
        findComb(0, n, current, nums, target);
        return answer;
    }
};