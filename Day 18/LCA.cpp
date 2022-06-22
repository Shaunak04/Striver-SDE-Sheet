class Solution 
{
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL || root==p || root==q)
        {
            return root;
        }
        TreeNode* leftTree = lowestCommonAncestor(root->left, p,  q);
        TreeNode* rightTree = lowestCommonAncestor(root->right, p,  q);
        if(leftTree==nullptr) return rightTree;
        if(rightTree==nullptr) return leftTree;
        else return root;
    }
};