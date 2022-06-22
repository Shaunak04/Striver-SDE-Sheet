class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>> answer;
        deque<TreeNode*> dq;
        int dir=1;
        TreeNode* temp;
        answer.push_back({root->val});
        dq.push_back(root);
        while(!dq.empty())
        {
            vector<int> curLevel;
            int levelsize = size(dq);
            for(int i=0;i<levelsize;i++)
            {
                if(dir%2==0)
                {
                    temp = dq.back();
                    dq.pop_back();
                }
                else
                {
                    temp = dq.front();
                    dq.pop_front();
                }
                if(dir%2==0)
                {
                    if(temp->left!=NULL) 
                    {
                        dq.push_front(temp->left);
                        curLevel.push_back(temp->left->val);
                    }
                    if(temp->right!=NULL) 
                    {
                        dq.push_front(temp->right);
                        curLevel.push_back(temp->right->val);
                    }
                }
                else
                {
                    if(temp->right!=NULL)
                    {
                        dq.push_back(temp->right);
                        curLevel.push_back(temp->right->val);
                    }
                    if(temp->left!=NULL)
                    {
                        dq.push_back(temp->left);
                        curLevel.push_back(temp->left->val);
                    }
                }
            }
            dir++;
            if(!curLevel.empty()) answer.push_back(move(curLevel));
        }
        return answer;
    }
};