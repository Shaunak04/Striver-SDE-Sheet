class Solution 
{
public:
    string reverseWords(string s) 
    {
        stringstream strm(s);
        stack<string> st;
        string output="";
        string word;
        while(strm>>word)
        {
            st.push(word);
        }
        while(st.size()!=1)
        {
            output+=st.top()+" ";
            st.pop();
        }
        output+=st.top();
        return output;
    }
};