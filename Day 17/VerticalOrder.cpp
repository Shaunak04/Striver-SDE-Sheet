class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        vector<vector<int>> answer;
        map<int, map<int, multiset<int>>> mp;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.second.first;
            int y = it.second.second;
            TreeNode* node= it.first;
            mp[x][y].insert(node->val);
            if(node->left)
            {
                q.push({node->left, {x-1,y +1}});
            }
            if(node->right)
            {
                q.push({node->right, {x+1, y+1}});
            }
        }
        for(auto n:mp)
        {
            vector<int> cols;
            for(auto q:n.second)
            {
                cols.insert(cols.end(), q.second.begin(), q.second.end());
            }
            answer.push_back(cols);
        }
        return answer;
    }
};