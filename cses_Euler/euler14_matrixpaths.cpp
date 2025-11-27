// ONLY RECURSION----------------------- O(2^ n+m)
long long ways(int i, int j, int n, int m) {
    
    if (i == n && j == m) return 1;     // reached bottom-right corner
    long long ans = 0;

    if (i + 1 <= n)     // move down
        ans += ways(i + 1, j, n, m);

    if (j + 1 <= m)     // move right
        ans += ways(i, j + 1, n, m);

    return ans;
}

// RESUCRION WITH MEMOIZATION-------- O(n*m)
int ways(int i, int j) {
    if (i == n && j == m) return 1;

    // memoized value
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if (i + 1 <= n) ans = (ans + ways(i + 1, j)) % MOD;

    if (j + 1 <= m) ans = (ans + ways(i, j + 1)) % MOD;

    return dp[i][j] = ans;
}
// PURE DP----------- O(min(m,n))
signed main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n+1 , vector<int>(m+1, 0));
    mat[n][m] = 1;
    for(int i=n; i>=0; i--){
        for(int j = m; j>=0; j--){
            if(i+1 <= n) mat[i][j] = ((mat[i][j]) + (mat[i+1][j])) %MOD ;
            if(j+1 <= m) mat[i][j] = ((mat[i][j]) + (mat[i][j+1])) %MOD ;
        }
    }
    cout<<mat[0][0]<<endl;
    
return 0;
}
