#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int n = days.back();
        vector<int> dp(n + 1, 0);
        unordered_set<int> st;

        // Mark travel days for O(1) membership checks while filling DP states.
        for (int d : days) {
            st.insert(d);
        }

        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) {
                dp[i] = dp[i - 1];
                continue;
            }

            int cost_1 = costs[0] + dp[max(0, i - 1)];
            int cost_7 = costs[1] + dp[max(0, i - 7)];
            int cost_30 = costs[2] + dp[max(0, i - 30)];

            // Transition: choose the pass that yields minimum cumulative spend up to day i.
            dp[i] = min({cost_1, cost_7, cost_30});
        }
        return dp[n];
    }
};

/*
Problem Statement:
You are given an array `days` where each value is a day of travel in the year, and an array `costs` where:
- costs[0] is the cost of a 1-day pass,
- costs[1] is the cost of a 7-day pass,
- costs[2] is the cost of a 30-day pass.
Return the minimum total cost required to cover all travel days.

Test Case:
days = [1,4,6,7,8,20]
costs = [2,7,15]

Answer:
11
*/
