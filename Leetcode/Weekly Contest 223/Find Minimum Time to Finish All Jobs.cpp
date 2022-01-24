class Solution {
private:
    // Nice Question
        void solve(int ind, vector<int> &jobs, int &k, int &res, int curr_max, vector<int> &workerTime)
        {
            int N = jobs.size();
            if(res<=curr_max)return;
            if(ind==N)
            {
                res = min(res,curr_max);
                return;
            }
            set<int> S;
            for(int i=0;i<k;i++)
            {
                if(S.find(workerTime[i])==S.end())
                {
                    S.insert(workerTime[i]);
                    workerTime[i]+=jobs[ind];
                    solve(ind+1,jobs,k,res,max(curr_max,workerTime[i]),workerTime);
                    workerTime[i]-=jobs[ind];
                }
            }
        }
public:
        int minimumTimeRequired(vector<int>& jobs, int k) {
        int res = INT_MAX;
        vector<int> workerTime(k);
        solve(0,jobs,k,res,0,workerTime);
        return res;
    }
};