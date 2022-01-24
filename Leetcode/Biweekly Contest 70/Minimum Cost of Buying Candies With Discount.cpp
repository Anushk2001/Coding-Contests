class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res = 0;
        sort(cost.begin(),cost.end());
        int N = cost.size();
        for(int i=N-1;i>=0;i-=3)
        {
            res+=cost[i];
            if(i-1>=0)
            res+=cost[i-1];
        }
        
        return res;
    }
};