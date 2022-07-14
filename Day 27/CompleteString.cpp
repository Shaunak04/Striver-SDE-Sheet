struct Node
{
    Node *children[26]; 
    bool isEnd = false; 
    
    bool containsKey(char ch) 
    {
        return (children[ch - 'a'] != NULL); 
    }
    Node* get(char ch) 
    {
        return children[ch-'a']; 
    }
    void put(char ch, Node* node) {
        children[ch-'a'] = node; 
    }
    void setEnd() 
    {
        isEnd = true; 
    }
    bool isEnd() 
    {
        return isEnd; 
    }
}; 

class Trie 
{
private: Node *root;

public:
    /** Initialize your data structure here. */
    Trie() 
    {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Node *node = root;
        for(int i = 0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i])) 
            {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }
    bool checkIfAllPrefixExists(string word) 
    {
        Node *node = root;
        bool isEnd = true; 
        for(int i = 0;i<word.size();i++) 
        {
            if(node->containsKey(word[i])) 
            {
                node = node->get(word[i]); 
                isEnd = isEnd & node->isEnd(); 
            }
            else 
            {
                return false; 
            } 
        }
        return isEnd; 
    }
};
string completeString(int n, vector<string> &a)
{
    Trie* obj = new Trie();
    for(auto word : a) obj->insert(word); 
    string longest = ""; 
    for(auto word: a) 
    {
        if(obj->checkIfAllPrefixExists(word)) 
        {
            if(word.size() > longest.size()) 
            {
                longest = word; 
            }
            else if(word.size() == longest.size() && word < longest) 
            {
                longest = word; 
            }
        }
    }
    if(longest == "") return "None"; 
    return longest; 
}