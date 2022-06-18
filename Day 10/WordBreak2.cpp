vector<string> ans;
string str;

void rec(string A,int l,unordered_set<string> &mp)
{
    int n = A.size();
    if(l==n)
    {
        str.pop_back();
        ans.push_back(str);
    }
    string s;
    for(int i=l; i<n; i++)
    {
        s.push_back(A[i]);
        if(mp.find(s)!=mp.end())
        {
            string temp=str;
            str+=s+" ";
            rec(A,i+1,mp);
            str=temp;
        }
    }
}
vector<string> Solution::wordBreak(string A, vector<string> &B) 
{
    unordered_set<string> mp;
    ans.clear();
    str.clear();
    for(auto x:B) mp.insert(x);
    rec(A, 0, mp);
    return ans;
}