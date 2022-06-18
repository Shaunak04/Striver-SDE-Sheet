class Solution {
public:
    vector<vector<int>> answer;
    void findComb(int index, int n,vector<int>& current, vector<int>& nums, int remaining)
    {
        if(remaining < 0)
        {
            return;
        }
        else if(remaining==0) 
        {
            answer.push_back(current);
        }
        else
        {
            for(int i=index; i<n; i++)
            {
                if(i>index && nums[i]==nums[i-1]) continue; // same as previous, just skip duplicates
                current.push_back(nums[i]); // give
                findComb(i+1, n, current, nums, remaining - nums[i]);
                current.pop_back(); // take
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<int> current;
        int n = nums.size();
        findComb(0, n, current, nums, target);
        return answer;
    }
};