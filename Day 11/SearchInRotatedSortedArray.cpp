class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size()-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            
            else if(nums[mid]>=nums[start]) // correct sorted format as we expect
            {
                if(target>=nums[start] && target<=nums[mid]) // if the number lies in sorted start and mid
                {
                    end = mid -1;
                }
                else
                {
                    start = mid+1;// array is sorted without rotation and we search from mid to end
                }
            }
            else
            {
                if(target<=nums[end] && target>=nums[mid]) // if number lies between mid to end becuase of rotation
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return -1;
        
    }
};