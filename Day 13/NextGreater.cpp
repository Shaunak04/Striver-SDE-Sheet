class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n  = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;

        for(int i = n-1; i>=0; i--)
        {
            int curr = nums2[i];
            while(!st.empty() && st.top()<curr)
            {
                st.pop();
            }
            mp[curr] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> ans(nums1.size(), -1);
        for (int i=0; i<(int)(nums1.size()); i++) 
        {
            auto itr = mp.find(nums1[i]);
            if (itr != mp.end()) 
            {
                ans[i] = itr->second;
            }
        }
        return ans;
    }
};