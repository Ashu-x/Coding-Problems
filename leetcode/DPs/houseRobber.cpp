int rob(vector<int>& nums){
    int n = nums.size();
    if(n<2) return nums[0];
    int last = nums[0] , secondLast = 0; //secondLast = dp[i-2] and last = dp[i-1]
    for(int i=1; i<n; i++){
        int temp = nums[i] + secondLast;
        secondLast = last;
        last = max(last,temp);
    }
    return last;

    // Another Approach using dp array
    vector<int> dp(n,0);
    dp[0] = nums[0], dp[1] = max(nums[0],nums[1]);
    for(i=2; i<n; i++){
        dp[i] = amx(nums[i] + dp[i-2] , dp[i-1]);
    }
    return dp[n-1];
}

