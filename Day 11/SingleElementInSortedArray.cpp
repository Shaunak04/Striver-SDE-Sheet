class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int start = 0;
        int n = nums.size();
        int end = nums.size()-1;
        while(start<end)
        {
            int mid = start + (end-start)/2;
            if((mid%2==0 && mid+1<n && nums[mid]==nums[mid+1]) ||
               (mid%2==1 && mid-1>=0 && nums[mid]==nums[mid-1]))
            {
                start = mid + 1;
            }
            else
            {
                end = mid-1;
            }
            if(mid-1 >=0 && mid+1 <n && nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
        }
        return nums[start];
    }
};