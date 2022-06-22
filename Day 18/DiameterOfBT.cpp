class Solution 
{
public:
    int helper(TreeNode* root, int &d) 
    {
        if(root==NULL) 
        {
            return 0;
        }
        int tl = helper(root->left, d);
        int tr = helper(root->right, d);
        d = max(tl+tr,d);
        return max(tr,tl)+1;    
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int d = 0;
        helper(root, d);
        return d;    
    }
};