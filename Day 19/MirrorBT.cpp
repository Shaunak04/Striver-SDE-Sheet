void mirror(Node* root) 
{
    if(!root)
    {
        return;
    }
    else
    {
        if(root->left)
        {
            mirror(root->left);
        }
        if(root->right)
        {
            mirror(root->right);
        }
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}