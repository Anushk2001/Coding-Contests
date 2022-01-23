class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        map<int,int> Mp;
        for(int &x:nums)
        {
            Mp[x]++;
        }
        for(int &x:nums)
        {
            if(Mp[x]==1&&Mp.find(x+1)==Mp.end()&&Mp.find(x-1)==Mp.end())
            {
                res.push_back(x);
            }
        }
        return res;
    }
};