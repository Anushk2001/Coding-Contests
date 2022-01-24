#include <bits/stdc++.h>
class Solution {
public:

    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>  > res;
        map<int,vector<pair<int,int> > > Mp;
        queue<vector<int> > Q;
        Q.push({start[0],start[1],0});
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > vis(n+1,vector<int> (m+1));
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        vis[start[0]][start[1]] = 1;
        while(!Q.empty())
        {
            int I = Q.front()[0];
            int J = Q.front()[1];
            int D = Q.front()[2];
            Q.pop();
            if(grid[I][J]>=pricing[0]&&grid[I][J]<=pricing[1])
            {
                Mp[D].push_back({I,J});
            }
            for(int c=0;c<4;c++)
            {
                int x = I+dx[c];
                int y = J+dy[c];
                if(x>=0&&y>=0&&x<=n-1&&y<=m-1&&vis[x][y]==0&&grid[x][y]!=0)
                {
                    vis[x][y] = 1;
                    Q.push({x,y,D+1});
                }
            }
        }
        for(auto &it:Mp)
        {
            vector<pair<int,int> > temp = it.second;
            std::sort(temp.begin(),temp.end(),[&](const pair<int,int> &p1,const pair<int,int> &p2)
             {
                 int i1 = p1.first;
                 int i2 = p2.first;
                 int j1 = p1.second;
                 int j2 = p2.second;
                 if(grid[i1][j1]<grid[i2][j2])
                return true; 
                 else if(grid[i1][j1]>grid[i2][j2])
                return false; 
                 if(i1<i2)return true;
                 if(i1>i2)return false;
                 if(j1<j2)return true;
                 return false;
                 
             });
            for(auto &x:temp)
            {
                if(res.size()==k)break;
                res.push_back({x.first,x.second});
            }
        }
        return res;
    }
};