class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> answer;
        stack<TreeNode*> st;
        if(root==NULL)
        {
            return answer;
        }
        TreeNode* curr = root;
        while(curr!=NULL || st.empty()==false)
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            answer.push_back(curr->val);
            curr =  curr->right;
        }
        return answer;
    }
};