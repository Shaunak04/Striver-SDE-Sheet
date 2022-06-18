class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==nullptr or k==0 or head->next==nullptr) return head; // if no or 1 node or k==0 return 
        
        int lenlist = 1;
        ListNode* curr = head;
        while(curr->next!=nullptr)
        {
            curr = curr->next;
            lenlist++;
        }
        curr->next=head;
        curr = head;
        k = k%lenlist;
        int shiftfromend = lenlist - k;
        while(shiftfromend-->1)
        {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};