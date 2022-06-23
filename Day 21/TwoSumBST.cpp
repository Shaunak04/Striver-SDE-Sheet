class Solution 
{
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) 
    {
        if(root==NULL)
        {  
            return false;
        }
        int target = k-root->val;
        if(st.count(target)) return true;
        st.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right,k);
        
    }
};