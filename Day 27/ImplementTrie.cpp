class Trie 
{
private:
    // 2 data variables -> boolean is_leaf, Trie array children of size 26
    bool is_leaf;
    Trie* children[26];
public:
    Trie() // initialize
    {
        this->is_leaf = false;
        for(int i=0;i<26;i++)
        {
            this->children[i] = NULL;
        }
    }
    
    void insert(string word) 
    {
        Trie* root = this;
        for( int i=0; i< word.length(); i++ )
        {
            int index = word[i] - 'a'; // 0-25
            if(root->children[index]==NULL)
            {
                root->children[index] = new Trie();
            }        
            root = root->children[index];
        }
        root->is_leaf = true;
    }
    
    bool search(string word) 
    {
        if(this==NULL) return false;
        
        Trie* root = this;
        for(int i=0; i<word.length();i++)
        {
            int index = word[i]-'a';
            root = root->children[index];
            if(!root)
            {
                return false;
            }
        }
        return root->is_leaf;
    }
    
    bool startsWith(string prefix) 
    {
        if(this==NULL)
        {
            return false;
        }
        Trie* root=this;
        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i]-'a';
            root = root->children[index];
            if(!root) return false;
        }
        return true;
    }
};