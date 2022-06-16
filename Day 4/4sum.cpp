class Solution 
{

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        set<vector<int>> helper;
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                int rest = target-nums[i]-nums[j];
                int start= j+1;
                int end = nums.size()-1;
                
                while(start<end)
                {
                    long long sum= nums[start] + nums[end];
                    if(sum==rest)
                    {
                        helper.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                    else if(sum<rest)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
            }
        }
        
        for(auto x : helper)
            res.push_back(x);
        
        return res;
    }
};