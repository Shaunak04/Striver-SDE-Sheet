class Solution 
{
public:
    int partition(vector<int> &nums, int l, int r)
    {     //partitioning in decreasing order
        int pivot = nums[r];
        int i = l - 1;
        for(int j=l;j<r;j++)
        {
            if(nums[j] >= pivot)
            {
                i++;
                swap(nums[i],nums[j]);
                
            }
        }
        swap(nums[i+1],nums[r]); // swap left and right
        return (i+1); // return left
    }
    int quickSelect(vector<int>& nums, int l, int r, int k)
    {
        int p = partition(nums,l,r);
        if(p==k-1)
        {
            return nums[p];
        }
        if(p>k-1)
        {
            return quickSelect(nums, l, p-1,k); // bound the end
        }
        else
        {
            return quickSelect(nums, p+1, r, k);// bound the start
        }
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        return quickSelect(nums, 0, n-1, k);
    }
};