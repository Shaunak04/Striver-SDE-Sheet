// block = k/fact
// add nums[block] to ans, erase from nums
// k = k%fact
// fact = fact/nums.size()
class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        int fact = 1;
        vector<int> number;
        for(int i=1; i<n; i++)
        {
            fact = fact*i;
            number.push_back(i);
        }
        
        number.push_back(n);
        string ans = "";
        k--;
        // the block is k/fact
        // then add the answer at number[block] and also erase the number at that index
        // if empty array break;
        // k = k%fact, fact = fact/nums.size
        while(true)
        {
            int block = k/fact;
            ans = ans + to_string(number[block]);
            number.erase(number.begin() + block);
            if(number.size()==0)
            {
                break;
            }
            k = k % fact;
            fact = fact / number.size();
        }
        return ans;
    }
};