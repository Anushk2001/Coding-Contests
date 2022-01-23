class Solution {
public:

    int maximumGood(vector<vector<int>>& statements) {
        int N = statements.size();
        int res = 0;
        vector<pair<int,int>  > Ad[N+1];

        int mask = (1<<N)-1;
        for(int i=0;i<=mask;i++)
        {
            int Bits = 0;
            queue<int > Q;
            vector<int> vis(N+1,0);
            for(int j=0;j<N;j++)
            {
                if((i&(1<<j)))
                {
                    Q.push(j);
                    vis[j] = 1;
                    Bits++;
                }
            }
            // cout<<i<<" "<<Bits<<"   ";
            int F = 1;
            while(!Q.empty()&&F==1)
            {
                int Node = Q.front();
                Q.pop();
                for(int j=0;j<N;j++)
                {
                    if(statements[Node][j]==0)
                    {
                        if(vis[j]==1)
                        {
                            F = 0;
                        }
                    }
                    else if(statements[Node][j]==1)
                    {
                        if(vis[j]==0)
                        {
                            F = 0;
                        }
                    }
                }
            }
            if(F==1)
            {
                res = max(res,Bits);
            }
        }
        
        return res;
    }
};
