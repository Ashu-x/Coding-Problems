vector<int> getRow(int rowIndex) {
    long long ans=1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1; col<rowIndex + 1; col++){
        ans = ans*(rowIndex - col + 1) ;
        ans = ans/(col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

// if we want to return matrix having the all rows we run funtion
vector<vector<int>> ans ;
for(int i=0; i<n; i++) ans.push_back(getRow(n));
return ans;

// DP approach
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> dp(numRows);

    for(int i = 0; i < numRows; i++) {
        dp[i].resize(i + 1);       // row length = i+1
        dp[i][0] = dp[i][i] = 1;   // first & last element = 1

        for(int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp;
}