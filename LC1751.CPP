
//LEETCODE HARD:1751
//problem name:MAXIMUM NUMBER OF EVENTS THAT CAN BE ATTENDED II
//I REALLY LIKED THIS PROBLEM
//DP+UPPER_BOUND 
//SIMILAIR TO MAXIMUM PROFIT IN JOB SCHEDULING
class Solution {
public:
    int n;
    vector<int> nxt;

    int f(vector<vector<int>>& events, int i, int k, vector<vector<int>>& dp) {
        if (i == n || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int skip = f(events, i + 1, k, dp);
        int take = events[i][2] + f(events, nxt[i], k - 1, dp);

        return dp[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();

        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        // 🔥 precompute next index:VVVI OPTIMIZATION
        //WITHOUT THIS OPTIMISATION,THIS PROBLEM WOULD GIVE U TLE AT 68/70 TEST CASES
        nxt.resize(n);
        vector<int> starts;
        for (auto &e : events) starts.push_back(e[0]);
//OPTIMISATION 1:USE UPPER BOUND INSTEAD OF LIINEAR SEARCH
//OPTIMISATION 2:PRECOMPUTE NEXT INDEX BY UPPER BOUND IN THE BEGINNING 
//OF THE FUNCTION INSTEAD OF CALCULATING IT EVERY TIME IN THE RECURSION
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();
            nxt[i] = idx;
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(events, 0, k, dp);
    }
};
