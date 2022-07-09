class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int, int>> pq;
        int i=0;
        map<int, int> mp;
        for(int &n:nums)
        {
            mp[n]++;
        }
        for(auto &pair: mp)
        {
            pq.push({pair.second, pair.first});
        }
        vector<int> answer;
        while(k-->0)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};