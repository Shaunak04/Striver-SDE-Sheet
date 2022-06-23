class Codec
{
public:
    string serialize(TreeNode* root)
    {
        if(!root)
        {
            return "#";
        }
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }
    
    TreeNode* des(istringstream& ss)
    {
        string str;
        ss>>str;
        if(str=="#")
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(str));
        root->left = des(ss);
        root->right = des(ss);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream ss(data);
        return des(ss);
    }
};