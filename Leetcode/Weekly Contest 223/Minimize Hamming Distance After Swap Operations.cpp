class Solution {
public:
    void dfs(vector<int> Ad[],vector<int> &vis,vector<int> &temp,int node)
    {
        vis[node] = 1;
        temp.push_back(node);
        for(auto &child:Ad[node])
        {
            if(vis[child]==-1)
            {
                dfs(Ad,vis,temp,child);
            }
        }
        return;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int res = 0;
        int N = source.size();
        vector<int> Ad[N];
        for(auto &it:allowedSwaps)
        {
            Ad[it[0]].push_back(it[1]);
            Ad[it[1]].push_back(it[0]);
        }
        vector<int> vis(N+1,-1); 
        for(int i=0;i<=N-1;i++)
        {
            if(vis[i]==-1)
            {
                vector<int> temp;
                dfs(Ad,vis,temp,i);
                map<int,int> Mp;
                for(int &I:temp)
                {
                    Mp[source[I]]++;
                }
                for(int &I:temp)
                {
                    if(Mp[target[I]])
                    {
                        res++;
                        Mp[target[I]]--;
                    }
                }
            }
        }
        return N-res;
    }
};