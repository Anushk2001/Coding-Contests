class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int,int> Mp;
        int res = 0 ;
        int maxi = 0;
        for(auto &it:rectangles)
        {
            int Len = min(it[0],it[1]);
            Mp[Len]++;
            maxi = max(maxi,Len);
        }
        res = Mp[maxi];
        return res;
    }
};