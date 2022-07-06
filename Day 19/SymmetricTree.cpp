class Solution
{
public:
    bool HelperFunc(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if(root1!=NULL && root2!=NULL && root1->val==root2->val)
        {
            return HelperFunc(root1->left,root2->right) && HelperFunc(root1->right,root2->left);
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root)
    {
        if(root==NULL)
        {
            return true;
        }
        return HelperFunc(root,root);
    }
};