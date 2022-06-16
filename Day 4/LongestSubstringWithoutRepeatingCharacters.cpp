class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<int, int> dict;
        int start = -1;
        int maxLen = 0;
        for(int i=0; i!=s.size(); ++i)
        {
            if(dict.find(s[i])!=dict.end() && dict[s[i]] > start)
            {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};