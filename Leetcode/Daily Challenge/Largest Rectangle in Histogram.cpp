class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int n = A.size();
        vector<int> Left(n,0),Right(n,n-1);
        stack<int> S;
        for(int i=n-1;i>=0;i--)
        {
            while(S.size()&&A[S.top()]>A[i])
            {
                Left[S.top()] = i+1;
                S.pop();
            }
            S.push(i);
        }
        while(S.size())S.pop();
        for(int i=0;i<n;i++)
        {
            while(S.size()&&A[S.top()]>A[i])
            {
                Right[S.top()] = i-1;
                S.pop();
            }
            S.push(i);
        }
        long long int res = 0;
        for(int i=0;i<n;i++)
        {
            res = max(res,(long long)(A[i])*(long long)(Right[i]-Left[i]+1));
        }
        return res;
    }
};