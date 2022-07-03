int helper(vector<int>& A,int mid)
{
    int low = 0;
    int high = A.size()-1;
    while(low<=high)
    {
        int m = (low+high)>>1;
        if(A[m]<=mid)
        {
            low = m+1;
        }
        else{
            high = m-1;
        }
    }
    return low;
}

int Solution::findMedian(vector<vector<int>> &A) 
{
    int r = size(A);
    int c = size(A[0]);
    int left = 0;
    int half = (r*c)/2;
    int low = 1;
    int high = 1e9;
    while(low<=high)
    {
        int mid = (low+high)>>1;
        int cnt = 0;
        for(int i=0; i<r; i++)
        {
            cnt+=helper(A[i], mid);
        }
        if(cnt<=half)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return low;
}