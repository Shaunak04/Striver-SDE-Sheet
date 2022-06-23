class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int front;
    MyQueue() 
    {
    }
    
    void push(int x) 
    {
        while(!s1.empty())
        {
            int temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty())
        {
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }
    }
    
    int pop() 
    {
        if(s1.size()>0)
        {
            int temp = s1.top();
            s1.pop();
            return temp;
        }
        else return -1;
        
    }
    
    int peek() 
    {
        if(s1.size()>0)
        {
            return s1.top();
        }
        else return -1;
    }
    
    bool empty() 
    {
        return s1.empty();
    }
};