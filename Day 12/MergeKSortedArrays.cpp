class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<pair<int, pair<int, int>>> q; // value {arraynumber, arrayIndex}
        vector<int> ans;
        int i;
        
        for(i=0; i<k; i++)
        {
           q.push({arr[i][0] *-1, {i , 1}});    
        }
        for(i=0; i<k*k; i++)
        {
           auto it = q.top();
           int value = -it.first;
           int arrayNumber = it.second.first;
           int arrayIndex = it.second.second;
           q.pop();
           ans.push_back(value);
           if(arrayIndex!=k)
           {
               q.push({-arr[arrayNumber][arrayIndex],{arrayNumber , arrayIndex+1}});
           }
       }
       
       return ans;
    }
};