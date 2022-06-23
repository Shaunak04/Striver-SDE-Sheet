int Floor(node *root, int input)
{
    // Base case
    if (root == NULL)
        return -1;
  
    // We found equal key
    if (root->key == input)
        return root->key;
  
    // If root's key is larger, floor must be in left subtree
    if (root->key > input)
        return Floor(root->left, input);
  
    // Else, either right subtree or root has the floor value
    else{
        int floor = Floor(root->right, input);
        // exception for -1 because it is being returned in base case
        return (floor<=input && floor!=-1)? floor : root->key; 
    }
}