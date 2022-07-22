/*
You are given a list of integers rod_lens, where each element represents the length of a rod. 
You are also given integers profit_per_len and cost_per_cut. You make profit_per_len profit per unit 
length of a rod but you can only sell rods that are all of the same length. You can also cut a rod 
into two integer pieces but each cut costs cost_per_cut. You can cut a rod as many times as you want. 
Return the maximum profit that can be made.
*/

int solve(vector<int>& rod_lens, int profit_per_len, int cost_per_cut) 
{
    int ans = 0;
    int temp;
    int t;
    int maxx = 0;
    for(int x:rod_lens)
    {
        maxx = max(maxx, x);
    }

    for(int l = 1; l<=maxx; l++)
    {
        temp = 0;
        for(int x:rod_lens)
        {
            t = profit_per_len*l*(x/l) - cost_per_cut*((x-1)/l);
            if(t>0) temp+=t;
        }
        ans = max(ans, temp);
    }
    return ans;
}