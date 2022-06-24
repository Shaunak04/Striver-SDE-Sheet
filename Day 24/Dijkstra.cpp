class Solution
{
	public:

    vector <int> dijkstra(int n, vector<vector<int>> graph[], int source)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, source});
        vector<int> distTo(n, INT_MAX);
        distTo[source] = 0;
        while(!pq.empty())
        {
            int prevDist = pq.top().first;
            int prevNode = pq.top().second;
            pq.pop();
            for(auto it:graph[prevNode])
            {
                int newNode = it[0];
                int newDist = it[1]+prevDist;
                if(newDist < distTo[newNode])
                {
                    distTo[newNode] = newDist;
                    pq.push({newDist, newNode});
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            ans.push_back(distTo[i]);
        }
        return ans;
    }
};
