class Solution
{
    public:
    
    static bool cmp(pair<int,double> a, pair<int,double> b) // descending order of value/weight
    {
        return a.second > b.second;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int,double>> v;
        double pro=0;
        double fraction [n] = {0};
        
        for(int i=0; i<n; i++)
        {
            v.push_back(make_pair(i,(double) arr[i].value/arr[i].weight));
        }
        
        sort(v.begin(),v.end(),cmp);
        
        for(auto i:v)
        {
            if(arr[i.first].weight <= W)
            {
                W -= arr[i.first].weight;
                fraction[i.first] = 1;
            }
            else
            {
                fraction[i.first] = (double) W/arr[i.first].weight;
                W = 0;
            }
        }
        for(int i=0; i<n; i++)
        {
            pro += fraction[i]*arr[i].value;
        }
        return pro;
    }
};