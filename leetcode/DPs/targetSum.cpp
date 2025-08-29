int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end() , 0) ;

        if(sum < target || (sum-target)%2 == 1) return 0;
        int newTarget= (sum - target)/2; 
        vector<int> dp(newTarget+1 , 0);
        dp[0] = 1;
        for(int num:nums){
            for(int j=newTarget; j>= num; j--){
                dp[j] += dp[j-num];
            }
        }
        return dp[newTarget];
}