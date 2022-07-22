vector<int> Solution::solve(vector<vector<int> > &arr) 
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; // value {arraynumber, arrayIndex}
    vector<int> ans;
    int i;
    int k = arr.size();
    for(i=0; i<k; i++)
    {
        q.push({arr[i][0], {i , 0}});    
    }
    int n = arr[0].size();
    while(!q.empty())
    {
        auto it = q.top();
        int value = it.first;
        int arrayNumber = it.second.first;
        int arrayIndex = it.second.second;
        q.pop();
        ans.push_back(value);
        if(arrayIndex!=(n-1))
        {
            q.push({arr[arrayNumber][arrayIndex+1],{arrayNumber , arrayIndex+1}});
        }
    }
    return ans;
}
