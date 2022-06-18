class Solution {
public:
    vector<vector<int>> answer;
    void findSet(int n, int index, vector<int>& currentSet, vector<int>& nums)
    {
        answer.push_back(currentSet);
        for(int i=index; i<n; i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue; // skip duplicates
            currentSet.push_back(nums[i]); // give
            findSet(n, i+1, currentSet, nums); // recursive
            currentSet.pop_back(); // take
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> currentSet;
        sort(nums.begin(), nums.end());
        findSet(n, 0,currentSet, nums);
        return answer;
    }
};