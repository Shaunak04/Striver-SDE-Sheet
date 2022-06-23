class Solution
{
    public:
    int ans = 0;
    void helper(Node* root, int k, int& c)
    {
        if(!root || c>=k) return;
        helper(root->right, k, c);
        c++;
        if(k==c) 
        {
            ans = root->data;
            return;
        }
        helper(root->left, k, c);
    }
    
    int kthLargest(Node *root, int K)
    {
        if(!root) return -1;
        int c = 0;
        helper(root, K, c);
        return ans;
    }
};