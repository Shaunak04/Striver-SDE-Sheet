class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int sum = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            sum += A[i];
            if(A[i] == 0 && maxLen == 0)
                maxLen = 1;
            if(sum==0)
                maxLen = i + 1;
            if(mp.find(sum)!=mp.end())
            {
                maxLen = max(maxLen, i-mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};