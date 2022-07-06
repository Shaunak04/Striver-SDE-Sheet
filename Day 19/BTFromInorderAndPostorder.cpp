class Solution
{
private:
    map<int, int> mp;

public:
    TreeNode* MakeBT(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int poL, int poR)
    {
        if(inL>inR || poL>poR)
        {
            return NULL;
        }
        int val = postorder[poR];
        TreeNode* root = new TreeNode(val);
        int index  = mp[val];
        root->left = MakeBT(inorder, postorder, inL, index-1, poL, poL+index-inL-1);
        root->right = MakeBT(inorder, postorder, index+1, inR, poL+index-inL, poR-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size();
        int m = postorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return MakeBT(inorder, postorder, 0, n-1, 0, m-1);
    }
};