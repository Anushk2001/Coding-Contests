class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0;
        int row  = matrix.size();
        int col  = matrix[0].size();
        vector<int> dp(col,0);
        for(int i=0;i<row;i++)
        {
            vector<int> temp;
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)dp[j]=0;
                else dp[j]++;
                temp.push_back(dp[j]);
            }
            sort(temp.begin(),temp.end());
            for(int j=0;j<col;j++)
            {
                res = max(res,(col-j)*temp[j]);
            }
        }
        return res;
    }
};