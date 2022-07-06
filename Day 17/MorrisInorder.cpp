vector<int> inorderTraversal(node * root) 
{
  vector<int> inorder;

  node* cur = root;
  while(cur!=NULL) 
  {
    if(cur->left == NULL) // case1
    {
      inorder.push_back(cur->data);
      cur = cur->right;
    } 
    else 
    {
      node* prev=cur->left;
      while(prev->right!=NULL && prev->right!=cur) 
      {
        prev = prev->right;
      }

      if(prev->right==NULL) // case 2
      {
        prev->right=cur;
        cur = cur->left;
      } 
      else // case 3 
      {
        prev->right = NULL;
        inorder.push_back(cur->data);
        cur = cur->right;
      }
    }
  }
  return inorder;
}