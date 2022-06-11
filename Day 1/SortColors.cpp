class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int low = 0 ;
        int high = nums.size()-1;
        int mid = 0;
        while(mid<=high && low<=high)
        {
            if(nums[mid]==0)
            {
                nums[mid] = nums[low];
                nums[low] = 0;
                low++;
                mid++;
            }
            else if(nums[mid]==2)
            {
                nums[mid] = nums[high];
                nums[high] = 2;
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};