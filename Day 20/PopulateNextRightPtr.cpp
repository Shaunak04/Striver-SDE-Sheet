class Solution 
{
public:
    void dfs(Node* root)
    {
        if(!root) return;
        if(root->left)
        {
            root->left->next = root->right;
        }
        if(root->right)
        {
            root->right->next = root->next ? root->next->left : NULL;
        }
        dfs(root->left);
        dfs(root->right);
    }
    
    Node* connect(Node* root) 
    {
        if(!root) return NULL;
        root->next = NULL;
        dfs(root);
        return root;
    }
};