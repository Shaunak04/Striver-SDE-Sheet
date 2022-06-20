class Solution 
{
public:
    /*
    Logic:
    1. Skip leading whitespace
    2. Check if negative/positive sign is present
    3. If a digit is encountered, add it to base, 
    4. If integer overflows, return INT_MAX / INT_MIN
    */
    int myAtoi(string str) 
    {
        int sign = 1;
        int base = 0;
        int i = 0;
        while(str[i] == ' ') { i++;} // skip leading whitespaces
        if(str[i] == '-') 
        {
            sign = -1;
            i++;
        }
        else if(str[i]=='+')
        {
            i++;
        }
        while(isdigit(str[i])) 
        {
            if(base >  INT_MAX/10  || (base == INT_MAX/10 && str[i] - '0' > 7)) 
            {
                if(sign==1) return INT_MAX;
                else return INT_MIN;
            }
            base  = 10*base + (str[i++] - '0');
        }
        return base*sign;
    }
};