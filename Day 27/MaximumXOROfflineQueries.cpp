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

	int getMax(int num) 
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int q = queries.size();
        vector<int> ans(q, -1);
        for(int i=0; i<queries.size(); i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [&](vector<int>& p1, vector<int>& p2)
             {
                return p1[1] < p2[1]; 
             });

        Trie t;
        int ind = 0;
        for(auto q:queries)
        {
            int ansIndx = q[2];
            int toXor = q[0];
            int maxLim = q[1];
            while(ind<n && nums[ind]<=maxLim)
            {
                t.insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[ansIndx] = -1;
            else ans[ansIndx] = t.getMax(toXor);
        }
        return ans;
    }
};