class Solution 
{
public:
    vector<int> temp;
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root==NULL) return{};
        if(root->left!=NULL) postorderTraversal(root->left);
        if(root->right!=NULL) postorderTraversal(root->right);
        temp.push_back(root->val);
        return temp;
    }
};