class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)
        {
            return NULL;
        }
        ListNode* tempB = headB;
        ListNode* tempA = headA;
        while(tempA!=NULL && tempB!=NULL && tempA!=tempB)
        {
            tempA=tempA->next;
            tempB=tempB->next;
            if(tempA==tempB)
            {
                return tempA;
            }
            if(tempA==NULL)
            {
                tempA= headB;            
            }
            if(tempB==NULL)
            {
                tempB= headA;            
            }
        }
        return tempA;
    }
};