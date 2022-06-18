class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        ListNode* nextnode;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            nextnode = slow->next; 
            slow->next = prev;
            prev = slow;
            slow = nextnode;  
        }
        
        slow = (fast ? slow -> next : slow);
        while(slow)
        {
            if(slow -> val != prev -> val) 
            {
                return false;
            }
            else slow = slow -> next;
            prev = prev -> next;
        }
	    return true;
    }
};