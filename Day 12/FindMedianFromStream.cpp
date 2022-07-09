class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(left.size() > (right.size()+1))
        {
            right.push(left.top());
            left.pop();
        }
        else if(left.size()+1 < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    void insertHeap(int &x)
    {
        if(left.empty() || left.top() > x)
        {
            left.push(x);
        }
        else
        {
            right.push(x);
        }
        balanceHeaps();
    }
    
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size()==right.size())
        {
            return left.empty() ? 0 : (left.top() + right.top())/2.0;
        }
        else
        {
            return (left.size() > right.size()) ? left.top() : right.top();
        }
    }
};
