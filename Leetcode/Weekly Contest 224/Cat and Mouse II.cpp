class Solution {
private:
    // Great Question
    int cx,cy,mx,my;
    int row,col;
    int maxPossibleRounds = 100;
    int Dp[8][8][8][8][101];
    vector<pair<int,int> > mouseStep[8][8];
    vector<pair<int,int> > catStep[8][8];
    vector<pair<int,int>> steps(vector<string>& grid,int x, int y, int maxLen)
    {
        vector<pair<int,int> > res;
        res.push_back({x,y});
        for(int dx=-1;dx<=1;dx++)
        {
            for(int dy=-1;dy<=1;dy++)
            {
                if(abs(dx)+abs(dy)==1)
                {
                    for(int l=1;l<=maxLen;l++)
                    {
                        int X= x+dx*l;
                        int Y= y+dy*l;
                        if(X<0||Y<0||X>=row||Y>=col)break;
                        if(grid[X][Y]=='#')break;
                        res.push_back({X,Y});
                    }
                }
                
            }
        }
        return res;
    }
    int mouseTurn(vector<string>& grid,int cx,int cy,int mx,int my,int round)
    {
        if(round>=maxPossibleRounds)return 0;
        if(Dp[mx][my][cx][cy][round]!=-1)return Dp[mx][my][cx][cy][round];
        vector<pair<int,int> > allTurns = mouseStep[mx][my];
        for(auto &[x,y]:allTurns)
        {
            if(x==cx&&y==cy)continue;
            if(grid[x][y]=='F')return Dp[mx][my][cx][cy][round] = 1;
            if(!catTurn(grid,cx,cy,x,y,round+1))
            {
                return Dp[mx][my][cx][cy][round] = 1;
            }
        }
        return Dp[mx][my][cx][cy][round] = 0;
    }
    int catTurn(vector<string>& grid,int cx,int cy,int mx,int my,int round)
    {
        if(round>=maxPossibleRounds)return 1;
        if(Dp[mx][my][cx][cy][round]!=-1)return Dp[mx][my][cx][cy][round];
        vector<pair<int,int> > allTurns = catStep[cx][cy];
        for(auto &[x,y]:allTurns)
        {
            if(x==mx&&y==my)return Dp[mx][my][cx][cy][round] = 1;
            if(grid[x][y]=='F')return Dp[mx][my][cx][cy][round] = 1;
            if(!mouseTurn(grid,x,y,mx,my,round+1))
            {
                return Dp[mx][my][cx][cy][round] = 1;
            }
        }
        return Dp[mx][my][cx][cy][round] = 0;
    }
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        row = grid.size();
        col = grid[0].length();
        memset(Dp,-1,sizeof(Dp));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='C'){
                    cx = i, cy = j;
                    grid[i][j] = '.';
                }
                else if(grid[i][j]=='M'){
                    mx = i, my = j;
                    grid[i][j] = '.';
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mouseStep[i][j] = steps(grid,i,j,mouseJump);
                catStep[i][j] = steps(grid,i,j,catJump);
            }
        }
        return mouseTurn(grid,cx,cy,mx,my,0);
    }
};
