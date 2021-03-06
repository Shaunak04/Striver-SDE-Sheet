class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* sentinel = new ListNode(-1);
        ListNode* l = sentinel;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL) 
        {
            int sum = carry;
            if(l1 != NULL) 
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != NULL) 
            {
                sum += l2->val;
                l2 = l2->next;
            }
            
            l->next = new ListNode(sum % 10);
            carry = sum / 10;
            l = l->next;
        }
        
        if(carry != 0)
            l->next = new ListNode(carry);
        
        return sentinel->next;
    }
};