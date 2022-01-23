class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        vector<int> P,N;
        for(int &x: nums)
        {
            if(x>=0)P.push_back(x);
            else N.push_back(x);
        }
        for(int i=0;i<P.size();i++)
        {
            res.push_back(P[i]);
            res.push_back(N[i]);
        }
        return res;
    }
};