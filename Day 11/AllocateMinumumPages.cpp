class Solution 
{
    public:
    bool feasible(int nums[], int m, int threshold, int n)
    {
        int running = 0;
        int arr = 1;
        for(int i=0; i<n; i++)
        {
            int num = nums[i];
            running+=num;
            if(running>threshold)
            {
                arr++;
                running = num;
                if(arr>m) return false;
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int nums[], int n, int m) 
    {
        if(m>n) return -1;
        int left = *max_element(nums, nums+n);
        int right = accumulate(nums, nums+n, 0);
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(feasible(nums, m, mid, n))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};