struct Node
{
	Node* child[2]; // one for 0 and other for 1
};

class Trie 
{
	private:
    Node *root = new Node(); // the root node for trie
	
    public:
	Trie() 
    {
		root = new Node(); // create a node for new trie
	}

	void insert(int num) 
    {
		Node *node = root; // work on a copy of root, dont directly hinder with root node
		for(auto i=31; i>=0; i--) // since integers are being represented as 32 bits, store them in trie bit by bit from MSB to LSB
        {
			int bit = (num >> i) & 1; // get the ith bit in num
			if(node->child[bit] == NULL) // if the trie node for ith bit doesnt exist, create a new one
            {
				node->child[bit] = new Node();
			}
			node = node->child[bit]; // move to the node
		}
	}

	int maxXor(int num) 
    {
		Node *node = root; // work on a copy of root, dont directly hinder with root node
		int ans=0; // maximum opposite nodes found
		for(auto i=31; i>=0; i--) 
        {
			int bit = (num >> i) & 1; // get the ith bit in num
			if(node->child[!bit] != NULL) // the opposite node exists in trie
            {
				ans = ans | (1 << i); // set the ith node from MSB
				node = node->child[!bit];
			}
			else node = node->child[bit];
		}
		return ans;
	}
};

class Solution 
{
public:
	int findMaximumXOR(vector<int>& nums) 
    {
		Trie trie;
		int maxOpposite=0;
		for(auto i:nums) trie.insert(i); // insert all numbers in the array into trie

		for(auto i:nums) maxOpposite = max(maxOpposite, trie.maxXor(i)); // try finding the maximum number with most opposite nodes to maximize xor
		return maxOpposite;
	}
};