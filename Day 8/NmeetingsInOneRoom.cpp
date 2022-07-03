class Solution
{
private:
 
   bool static MyCmp(pair<int,int>& a, pair<int,int> &b)
   {
       return (a.second < b.second);
   }
   
public:
    // sort in ascending order of end times
   int maxMeetings(int start[], int end[], int n)
   {
       vector<pair<int, int>> vp, res;
       for(int i=0; i<n; i++) vp.push_back({start[i], end[i]});
       
       sort(vp.begin(), vp.end(), MyCmp);
       
       for(auto x:vp)
       {
           if(res.size()==0 || res.back().second < x.first) 
            res.push_back(x);
       }
       
       return res.size();
   }
};