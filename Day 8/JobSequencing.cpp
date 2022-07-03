class Solution 
{
    public:
    
    bool static comp(Job &j1, Job &j2)
    {
        return j1.profit > j2.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int numJob = 0;
        int totalProfit = 0;
        sort(arr, arr+n, comp);
        int maxDeadline = arr[0].dead;
        for(int i=1; i<n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        int slot[maxDeadline+1];
        memset(slot, -1, sizeof slot);
        for(int i=0; i<n; i++)
        {
            for(int j=arr[i].dead; j>0; j--)
            {
                if(slot[j]==-1)
                {
                    slot[j] = i;
                    numJob++;
                    totalProfit += arr[i].profit;
                    break;
                    
                }
            }
        }
        return {numJob, totalProfit};
    } 
};