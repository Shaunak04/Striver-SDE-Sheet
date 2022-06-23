class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> stack;
        for (auto c : s) 
        {
            switch(c)
            {
                case '(': stack.push(')'); continue;
                case '{': stack.push('}'); continue;
                case '[': stack.push(']'); continue;
            }

            if (!stack.empty() && (stack.top() == c))
            {
                stack.pop();
            }
            else
                return false;
        }
        if (!stack.empty()) return false;
        return true;
    }
};