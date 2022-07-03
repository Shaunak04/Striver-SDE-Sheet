void sortedInsert(stack<int> &stack, int key)
{
    if(stack.empty() || key > stack.top())
    {
        stack.push(key);
        return;
    }
  
    int top = stack.top();
    stack.pop();
    sortedInsert(stack, key);
    stack.push(top);
}

void sortstack(stack<int> &stack)
{
    if(stack.empty()) 
    {
        return;
    }
    int top = stack.top();
    stack.pop();
    sortstack(stack);
    sortedInsert(stack, top);
}