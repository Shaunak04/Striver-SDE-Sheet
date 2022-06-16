int Solution::solve(vector<int> &nums, int B) 
{
    int n = nums.size();
    unordered_map<int, int> mp; // map to check presence of prefix xor
    int xxx = 0; // runningxor
    int ans = 0; // total subarrays
    
    for(int i=0; i<n; i++)
    {
        xxx^=nums[i]; // update running xor
        if(xxx==B) // if runningxor==required xor, ans++
        {
            ans++;
        }
        if(mp.find(xxx^B)!=mp.end()) // if prefix xor of runningxor^requiredxor
                                // in map, add all the occurances of prefix xor
        {
            ans += mp[xxx^B]; 
        }
        mp[xxx]++; // update map with running xor
    }
    return ans;
}