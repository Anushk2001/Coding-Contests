class Solution {
public:
    int numberOfWays(string corridor) {
        long long int res = 0;
        long long int MOD = 1e9+7;
        int S = 0;
        int N = corridor.size();
        for(char &c:corridor)
        {
            if(c=='S')S++;
        }
        if(S==2)
        {
            res = 1;
        }
        else if(S%2==0&&S!=0)
        {
            int curr_s = 0;
            vector<long long int> dp(S+1);
            dp[0] = 1;
            for(int i=0;i<N;i++)
            {
                char c = corridor[i];
                if(c=='S')
                {
                    curr_s++;
                }
                dp[curr_s]++;
                // cout<<curr_s<<" ";
            }
            res = 1;
            for(int i=2;i<=S-2;i+=2)
            {
                res = (res*dp[i])%MOD;
            }
        }

        return res;
    }
};