vector<int> ans;
vector<int> leftView(Node *root)
{
    if(root==NULL)
    {
        return ans;
    }
    else
    {
        queue<Node*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()) 
        {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) 
            {
                auto top = q.front();
                if(i==0)
                {
                    ans.push_back(top->data);
                }
                q.pop();
                if(top -> left) q.push(top -> left);
                if(top -> right) q.push(top -> right);
                
            }
        }
        return ans;
    }
}