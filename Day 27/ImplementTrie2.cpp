class Trie 
{    
    struct TrieNode 
    {
        TrieNode* children[26];
        int word_cnt;
        int prefix_cnt;
        // Initialize your data structure here.
        TrieNode() 
        {
            memset(children, 0, sizeof(children));
            word_cnt = 0;
            prefix_cnt = 0;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() 
    {
        root = new TrieNode();
    }
    // iterate by characters, if child[index] does not exist, create new node and move temp to temp.child[index], increase prefix count, then after word, increase word count
    void insert(string word) 
    {
        TrieNode* tmp = root;
        for(char ch : word) 
        {
            int index = ch - 'a';
            if(tmp->children[index] == nullptr) {
                tmp->children[index] = new TrieNode();
            }
            tmp = tmp->children[index];
            tmp->prefix_cnt++;
        }
        tmp->word_cnt++;
    }
    // iterate character by character, if temp.child[index]==NULL return 0, in end return temp.wordCount
    int countWordsEqualTo(string word) 
    {
        TrieNode* tmp = root;
        for(char ch : word) 
        {
            int index = ch - 'a';
            if(tmp->children[index] == nullptr) 
            {
                return 0;
            }
            tmp = tmp->children[index];
        }
        return tmp->word_cnt;
    }
    // iterate char by char, if temp.child[index]==NULL return 0, after iterating the prefix, return temp.prefixCnt
    int countWordsStartingWith(string prefix) 
    {
        TrieNode* tmp = root;
        for(char ch : prefix) 
        {
            int index = ch - 'a';
            if(tmp->children[index] == nullptr) 
            {
                return 0;
            }
            tmp = tmp->children[index];
        }
        return tmp->prefix_cnt;
    }
    
    void erase(string word) 
    {
        TrieNode* tmp = root;
        TrieNode* to_be_deleted = nullptr;
        for(char ch : word) 
        {
            int index = ch - 'a';
            TrieNode* parent = tmp;
            tmp = tmp->children[index];
            tmp->prefix_cnt--;
            
            if (to_be_deleted != nullptr) 
            {
                delete to_be_deleted;
            }
            if (tmp->prefix_cnt == 0) 
            {
                if (to_be_deleted == nullptr) 
                {
                    parent->children[index] = nullptr;
                }
                to_be_deleted = tmp;
            }
        }
        tmp->word_cnt--;
        if (to_be_deleted != nullptr) 
        {
            delete to_be_deleted;
        }
    }
};