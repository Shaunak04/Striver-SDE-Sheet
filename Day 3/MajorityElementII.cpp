class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int y=-1;
        int z=-1;
        int cy=0;
        int cz=0;
        for(const auto &x:nums)
        {
            if(x==y) cy++;
            else if(x==z) cz++;
            else if(cy==0) y = x, cy=1;
            else if(cz==0) z = x, cz=1;
            else cy--, cz--;
        }

        cy = 0, cz = 0;
        for(const auto &x:nums)
        {
            if(x==y) cy++;
            else if(x==z) cz++;
        }
        vector<int> answer;
        if(cz>size(nums)/3) answer.push_back(z);
        if(cy>size(nums)/3) answer.push_back(y);
        return answer;
    }
};