class Solution 
{
public:
    
    int merge(vector<int>& A, int left, int mid, int right)
    {
        int i, j;
        int rev_count = 0;
        j = mid+1;
        for(i = left; i<=mid; i++)
        {
            while(j<=right && A[i] > 2LL*A[j])
            {
                j++;
            }
            rev_count += (j-(mid+1));
        }
        vector<int> temp;   
        i = left;
        j = mid+1;
        
        while((i<=mid) && (j<=right))
        {
            if(A[i]<=A[j])
            {
                temp.push_back(A[i++]);
            }
            else
            {
                temp.push_back(A[j++]);
            }
        }
        while(i<=mid)
        {
            temp.push_back(A[i++]);
        }
        while(j<=right)
        {
            temp.push_back(A[j++]);
        }
        for(int i=left; i<=right; i++)
        {
            A[i] = temp[i-left];
        }
        return rev_count;
    }
    
    
    int mergeSort(vector<int>& A, int left, int right)
    {
        int mid, rev_count = 0;
        if(left < right)
        {
            mid = (right+left)/2;
            rev_count += mergeSort(A, left, mid);
            rev_count += mergeSort(A, mid+1, right);
            rev_count += merge(A, left, mid, right);
        }
        return rev_count;
    }
    
    int reversePairs(vector<int>& A) 
    {
        int ans = 0;
        int n = A.size();
        ans = mergeSort(A, 0, n-1);
        return ans;
    }
};