int fact(int n)
{
    if(n>12)
        return INT_MAX;
    return (n==1 || n==0) ? 1: n * fact(n - 1);
}

string Solution::getPermutation(int N, int B) 
{
    
    vector<int> C;
    for(int i=1;i<=N;i++)
        C.push_back(i);
    
    string ans="";
    int block;
    for(int i=0;i<N;i++)
    {
        int p=fact(N-1-i);
        block=B/p;
        if(B%p==0)  
            block--;
        ans+=to_string(C[block]);
        C.erase(C.begin()+block);
        B=B-(block)*p;
    }
    return ans;
}