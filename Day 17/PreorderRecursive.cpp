class Solution 
{
private:
    vector<int> ans;
public:
    // root , left, right
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(root!=NULL)
        {
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans;
    }
};