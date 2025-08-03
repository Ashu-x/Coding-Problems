int minRemoval(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = n;
    for (int i = 0; i < nums.size(); i++) {
        int it = upper_bound(nums.begin(), nums.end(), nums[i] * 1LL * k) - nums.begin();
        it--;
        if (it >= i) {
        ans = min(ans, (int)nums.size() - (it - i + 1));
        }
    }
    return ans;
}