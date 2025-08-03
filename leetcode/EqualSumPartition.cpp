bool canPartition(vector<int>& nums) {
        int sum=0 , n = nums.size();
        for(int i:nums) sum += i;
        if(sum%2) return false;
        sum = sum/2 ;
        bool dp[n+1][sum + 1];
        for(int i=0; i<n+1; i++){
            dp[i][0] = true;
        }
        for(int j=1; j<sum+1; j++) dp[0][j] = false;

        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1] <=j){
                    dp[i][j] = dp[i-1][j- nums[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
    return dp[n][sum];
}

//SECOND approach using only O(sum+1) space
bool canPartition(vector<int>& nums) {
    int sum=0 , n = nums.size();
    for(int i:nums) sum += i;
    if(sum%2) return false;
    sum = sum/2 ;
    bool dp[sum+1] ;
    dp[0] = true;
    for(int i=0; i<n; i++){
        for(int j=sum; j>=n-1; j--){
            if(dp[j]) continue;
            if(dp[j-arr[i]]) dp[j] = true;
            if(dp[-1]) return true;
        }
    }
    return dp[-1];
}