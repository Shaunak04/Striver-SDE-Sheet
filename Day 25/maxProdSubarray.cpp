class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = nums[0];
        int maxPos = ans;
        int maxNeg = ans;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                swap(maxPos, maxNeg);
            }
            maxPos = max(nums[i], maxPos*nums[i]);
            maxNeg = min(nums[i], maxNeg*nums[i]);
            ans = max(ans, maxPos);
        }
        return ans;
    }
};