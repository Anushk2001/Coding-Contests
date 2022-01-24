class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        int x = first;
        res.push_back(x);
        for(int &G:encoded)
        {
            x^=G;
            res.push_back(x);
        }
        return res;
    }
};