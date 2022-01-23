class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int A = nums[0];
        int B = nums.back();
        int res = 0;
        for(int &x:nums)
        {
            if(x!=A&&x!=B)res++;
        }
        return res;
    }
};