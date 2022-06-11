class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int min_price = INT_MAX; // minimum price encountered till now
        int maxprofit = 0; // maxprofir earned by buying at minimum price
        
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < min_price) min_price = prices[i];
            else if(prices[i] - min_price > maxprofit) // else if because buy and sell days have to be different
            {
                maxprofit = prices[i] - min_price; // update max profit earned
            }
        }
        return maxprofit;    // return max profit earned
    }
};