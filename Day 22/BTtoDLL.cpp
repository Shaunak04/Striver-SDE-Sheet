class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void helper(Node *root, Node *&head,Node *&pre)
    {
       if(!root)
           return;
           
       helper(root->left, head, pre);
       
       if(!pre)
       {
           head = root;
       }
       else
       {
           root->left = pre;
           pre->right = root;
       }
       pre = root;
       helper(root->right, head, pre);
   }
   
    Node * bToDLL(Node *root)
    {
        Node *head = NULL, *pre = NULL;
        helper(root, head, pre);
        return head;
    }
};