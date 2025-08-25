int unboundedKnapsackDPComp(vector<int> &wgt, vector<int> &val, int cap) {
    int n = wgt.size();
    vector<int> dp(cap + 1, 0);
  
    for (int i = 1; i <= n; i++) {

        for (int c = 1; c <= cap; c++) {
            
            if (wgt[i - 1] > c) {
                dp[c] = dp[c];
            } else {
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[cap];
}