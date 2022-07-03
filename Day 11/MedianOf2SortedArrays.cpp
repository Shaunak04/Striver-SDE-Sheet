class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int n = array1.size();
        int m = array2.size();
        if(n>m)
        {
            return MedianOfArrays(array2, array1);
        }
        int start = 0;
        int end = n;
        int l1, l2, r1, r2;
        while(start<=end)
        {
            int cut1 = start+(end-start)/2;
            int cut2 = (m+n+1)/2 - cut1;
            
            l1 = cut1==0 ? INT_MIN : array1[cut1-1];
            r1 = cut1==n ? INT_MAX : array1[cut1];
            l2 = cut2==0 ? INT_MIN : array2[cut2-1];
            r2 = cut2==m ? INT_MAX : array2[cut2];
            
            if(l1>r2)
            {
                end = cut1-1;
            }
            else if(l2>r1)
            {
                start = cut1+1;
            }
            else
            {
                if((m+n)%2==1)
                {
                    return (double)max(l1, l2);
                }
                else
                {
                    return ((double)max(l1, l2) + (double)min(r1, r2))/2;
                }
            }
        }
        return -1;
    }
};