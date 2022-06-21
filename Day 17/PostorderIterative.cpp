// LEFT -> RIGHT -> ROOT

class Solution {
public:
    // 1 stack approach
    vector<int> postorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> postorder;
        
        if(root==nullptr) return postorder;
        while(!st.empty() || root!=nullptr)
        {
            if(root!=nullptr)
            {
                st.push(root);
                root = root->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp==nullptr)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right)
                    {   
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else{
                    root=temp;
                }
            }
        }
        return postorder;
    }
    
    
    // 2 stack approach
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st1, st2;
        vector<int> postorder;
        st1.push(root);
        if(root==nullptr) return postorder;
        while(!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=nullptr)
            {
                st1.push(root->left);
            }
            if(root->right!=nullptr)
            {
                st1.push(root->right);
            }
        }
        while(!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};