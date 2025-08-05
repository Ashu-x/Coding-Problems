int minDifference(vector<int>& arr) {
    int sum=0 , n = arr.size();
    for(int i:arr) sum += i;
    bool dp[n+1][sum + 1];
    for(int i=0; i<n+1; i++){
        dp[i][0] = true;
    }
    for(int j=1; j<sum+1; j++) dp[0][j] = false;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <=j){
                dp[i][j] = dp[i-1][j- arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<= sum/2; i++){
        if(dp[n][i]) {
            ans = min(ans , sum - 2*i);
        } 
    }
    return ans;
}