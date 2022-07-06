class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> minheap;
    int m_k;
public:
    KthLargest(int k, vector<int>& nums) {
        m_k=k;
        for(int x:nums)add(x);
    }
    
    int add(int val) {
        if(minheap.size()<m_k)minheap.push(val);
        else
        {
            if(val>minheap.top())
            {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};
