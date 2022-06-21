class Solution 
{
private:
    vector<int> ans;
public:
    // left, root, right
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root!=NULL)
        {  
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans;
    }
};