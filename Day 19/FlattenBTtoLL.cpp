class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        if(!root) return;
        while(root)
        {
            if(root->left)
            {
                TreeNode* iter = root->left;
                while(iter->right)
                {
                    iter = iter->right;
                }
                iter->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};