class Solution {
public:
    int majorityElement(vector<int>& arr) 
    {
        int count=0;
        int num=0;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            if(count==0){
                num = arr[i];
            }
            if(num==arr[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        if(count>0)
        {
            return num;
        }
        return 0;
    }
};