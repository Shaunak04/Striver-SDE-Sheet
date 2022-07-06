class Solution 
{
public:
    
    TreeNode* addNode(TreeNode* root, int i)
    {
        if(!root)
        {
            return new TreeNode(i);
        }
        else if(i>root->val)
        {
            root->right = addNode(root->right, i);
        }
        else
        {
            root->left = addNode(root->left, i);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        if(preorder.size()==0) return nullptr;
        TreeNode* root = nullptr;
        TreeNode* curr = root;
        for(int i:preorder)
        {
            root = addNode(root, i);
        }
        return root;
    }
};