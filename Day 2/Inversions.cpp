int merge(vector<int>& A, vector<int>& temp, int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while((i<=mid-1) && (j<=right))
    {
        if(A[i]<=A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            inv_count += (mid-i);
        }
    }
    while(i<=(mid-1))
    {
        temp[k++] = A[i++];
    }
    while(j<=right)
    {
        temp[k++] = A[j++];
    }
    for(int i=left; i<=right; i++)
    {
        A[i] = temp[i];
    }
    return inv_count;
}

int mergeSort(vector<int>& A, vector<int>& temp, int left, int right)
{
    int mid, inv_count = 0;
    if(left < right)
    {
        mid = (right+left/2);
        inv_count += mergeSort(A, temp, left, mid);
        inv_count += mergeSort(A, temp, mid+1, right);
        inv_count += merge(A, temp, left, mid+1, right);
    }
    return inv_count;
}

int Solution::countInversions(vector<int> &A) 
{
    int ans = 0;
    int n = A.size();
    vector<int> temp(n, 0);
    ans = mergeSort(A, temp, 0, n-1);
    return ans;
}