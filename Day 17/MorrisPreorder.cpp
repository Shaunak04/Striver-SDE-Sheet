vector<int> preorderTraversal(node * root) 
{
  vector<int> preorder;

  node * cur = root;
  while (cur != NULL)
   {
    if (cur->left == NULL) 
    {
      preorder.push_back(cur->data);
      cur = cur->right;
    } 
    else 
    {
      node * prev = cur->left;
      while (prev->right != NULL && prev->right != cur) 
      {
        prev = prev->right;
      }

      if (prev->right == NULL)
      {
        prev->right = cur;
        preorder.push_back(cur->data);
        cur = cur->left;
      } 
      else 
      {
        prev->right = NULL;
        cur = cur->right;
      }
    }
  }
}