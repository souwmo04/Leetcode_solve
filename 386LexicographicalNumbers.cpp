class Solution {
public:
    vector<int> result;
    int N;
    void recur(int x)
    {
        result.push_back(x);
        for(int i=0;i<10&&x*10+i<=N;i++)
            recur(x*10+i);
        return;
    }
    vector<int> lexicalOrder(int n) 
    {
        N=n;
        result.reserve(n);
        for(int i=1;i<10&&i<=n;i++)
            recur(i);
        return result;
    }
};