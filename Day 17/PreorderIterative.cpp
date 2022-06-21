class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> answer;
        stack<TreeNode*> st;
        if(root==NULL)
        {
            return answer;
        }
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            answer.push_back(curr->val);
            if(curr->left!=NULL)
            {
                st.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                st.push(curr->right);
            }
        }
        return answer;
    }
};