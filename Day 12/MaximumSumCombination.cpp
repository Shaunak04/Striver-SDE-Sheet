vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = A.size();
    int k = 0;
    while(k<C)
    {
        pq.push(A[k]+B[k]);
        k++;
    }
    for(int i=0; i<n ;++i)
    {
        for(int j=0; j<n;++j)
        {
            if(i!=j)
            {
                if((A[i]+B[j]) > pq.top())
                {
                    pq.pop();
                    pq.push(A[i]+B[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans;
    while(C--)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.rbegin(), ans.rend());
    return ans;
}
