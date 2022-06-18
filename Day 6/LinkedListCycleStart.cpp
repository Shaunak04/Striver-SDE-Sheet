class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *slow = head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;    
            fast=fast->next->next; 
            if(slow==fast) //loop found
            {
                while(slow!=head)  // to find where the loop  started
                {
                    slow=slow->next;
                    head=head->next;
                }
                return head;
            }

        }
        return NULL;
    }
};