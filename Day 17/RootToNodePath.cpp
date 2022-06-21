 void dfs(TreeNode* root, int node, vector<int> temp, vector<int> &ans)
 {
    if(root==nullptr) return;
    temp.push_back(root->val);
    if(node==root->val)
    { 
        ans = temp;
        return;
    }
    dfs(root->left, node, temp, ans);
    dfs(root->right ,node, temp, ans);
 }

vector<int> Solution::solve(TreeNode* root, int node) 
{
    vector<int> temp; vector<int> ans;
    dfs(root, node, temp, ans);
    return ans;
}