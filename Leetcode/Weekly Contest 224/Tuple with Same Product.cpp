class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> Mp;
        int res = 0;
        int N = nums.size();
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                res+=Mp[nums[i]*nums[j]]*8;
                Mp[nums[i]*nums[j]]++;
            }
        }
        return res;
    }
};