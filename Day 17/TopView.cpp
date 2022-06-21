class Solution
{
    public:
    void TopView(Node* root, int dis, int level, map<int, pair<int,int>>& mp)
    {
        if(!root) return;
        if(mp.find(dis)==mp.end() || level < mp[dis].second)
        {
            mp[dis] = {root->data, level};
        }
        TopView(root->left, dis-1, level+1, mp);
        TopView(root->right, dis+1, level+1, mp);
    }
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int, pair<int, int>> mp;
        TopView(root, 0, 0, mp);
        for(auto it:mp)
        {
            ans.push_back(it.second.first);
        }
        return ans;
    }
};