class BSTIterator
{
private:
    stack<TreeNode*> st;
public:
    
    void inorderPartial(TreeNode* root)
    {
        while(root!=nullptr) // 1st
        {
            st.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) 
    {
        inorderPartial(root);
    }
    
    int next() // 2nd
    {
        TreeNode* topNode = st.top();
        st.pop();
        inorderPartial(topNode->right);
        return topNode->val;
    }
    
    bool hasNext() 
    {
        return !st.empty();
    }
};