struct TrieNode
{
    TrieNode* children[26];
    bool isend;
    TrieNode()
    {
        for(int i=0;i<26;i++)
         children[i]=NULL;
         isend=false;
    }
};

int insert(TrieNode* root, string s, int j)
{
    TrieNode* curr = root;
    int ans = 0;
    for(int i = j; i<s.size(); i++)
    {
        int index = s[i]-'a';
        if(curr->children[index]==NULL)
        {
            ans++;
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->isend = true;
    return ans;
}

int countDistinctSubstring(string s)
{
    int ans = 0;
    TrieNode* root = new TrieNode();
    for(int i=0; i<s.size(); i++)
    {
        ans += insert(root, s, i);
    }
    return ans+1;
}