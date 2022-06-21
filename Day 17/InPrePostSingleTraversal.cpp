// output: {{pre}, {in}, {post}}

class Solution
{
    public:
    vector<vector<int>> PreInPostTraversal(TreeNode* root)
    {
        if(root==nullptr) return {};
        stack<pair<TreeNode*, int> st;
        st.push({root,1});
        vector<int> pre, in, post;
        while(!st.empty())
        {
            auto itr = st.top();
            st.pop();
            // PRE-ORDER, increment top exisiting node from 1->2 and push left side.
            if(itr.second==1)
            {
                pre.push_back(itr.first->val);
                itr.second++;
                st.push(itr);
                if(itr->first->left!=nullptr)
                {
                    st.push({itr->first->left,1});
                }
            }
            //IN-ORDER, increment top existing node from 2->3 and push right side.
            else if(itr.second==2)
            {
                in.push_back(itr.first->val);
                itr.second++;
                st.push(itr);
                if(itr->first->right!=nullptr)
                {
                    st.push({itr->first->right,1});
                }
            }
            //POST-ORDER 
            else{
                post.push_back(itr->first->val);
            }
        }
        return {pre, in, post};
    }
}