class Solution 
{
private: 
    
    //helper function to safe check whether a substr is palindrome or not
    bool isPalindrome(string& s, int l, int r) 
    {
        while (l < r) 
        {
            if (s[l++] != s[r--]) 
            {
                return false;
            }
        }
        return true;
    }
    

    void partition(string& s, int start, vector<string>& currentSet, vector<vector<string>>& result) 
    {
        int n = s.length();
        if(start==n) // recursion base condition
        {
            result.push_back(currentSet);
            return;
        } 

        for(int i = start; i < n; i++) 
        {
            if(isPalindrome(s, start, i)) 
            {
                currentSet.push_back(s.substr(start, i - start + 1)); // give
                partition(s, i + 1, currentSet, result);
                currentSet.pop_back(); // take
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        vector<string> currentSet;
        partition(s, 0, currentSet, result);
        return result;
    }
};