class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int res = 0;
        long long int  maxi_sub_array = -1e6;
        long long int mini_sub_array = 1e6;
        long long int curr1 = 0, curr2 = 0;;
        for(int &X:differences)
        {
            long long int x = X;
            curr1 = max(curr1+x,x);
            maxi_sub_array = max(maxi_sub_array,curr1);
            curr2 = min(curr2+x,x);
            mini_sub_array = min(mini_sub_array,curr2);
        }
        long long int N = max(abs(maxi_sub_array),abs(mini_sub_array));
        res = max(upper-lower+1-N,res);
        return res;
    }
};