#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("tune=native")
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        unordered_map<int, int> mp;
        for(auto const& i:nums)
        {
            mp[i] = 1;
        }
        int maxLen = 0;
        for(int i:nums)
        {
            if(mp.find(i-1)==mp.end())
            {
                int tempLen = 1;
                while(mp.find(i+1)!=mp.end())
                {
                    i++;
                    tempLen++;
                }
                maxLen = max(maxLen, tempLen);
            }
        }
        return maxLen;
        
    }
};