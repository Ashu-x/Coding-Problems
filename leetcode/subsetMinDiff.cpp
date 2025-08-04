bool canPartition(vector<int>& nums) {
        int sum=0 , n = nums.size();
        for(int i:nums) sum += i;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = sum; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i <= sum / 2; ++i) {
            if (dp[i]) {
                ans = min(ans, abs(sum - 2 * i));
            }
        }

        return ans;
}