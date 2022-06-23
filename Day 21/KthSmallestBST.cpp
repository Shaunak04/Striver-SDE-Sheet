class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty())
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            root = st.top();
            st.pop();
            if(--k==0)
            {
                break;
            }
            root=root->right;
        }
        return root->val;
    }
}