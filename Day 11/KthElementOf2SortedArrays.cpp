class Solution
{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        int num;
        while(ptr1<n and ptr2<m)
        {
           if(arr1[ptr1]>arr2[ptr2])
           {
               i++;
               if(i==k)
               {
                   return arr2[ptr2];
               }
               ptr2++;
           }
           else
           {
               i++;
               if(i==k) 
               {
                   return arr1[ptr1];
               }
               ptr1++;
           }
        }
        while(ptr1<n)
        {
            i++;
            if(i==k)
            {
                return arr1[ptr1];
            }
            ptr1++;
        }
        while(ptr2<m)
        {
            i++;
            if(i==k)
            {
                return arr2[ptr2];
            }
            ptr2++;
        }
    }
};