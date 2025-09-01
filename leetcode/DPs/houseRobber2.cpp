int rob(vector<int>& nums){
    int n = nums.size();
    if(n<2) return nums[0];
    int secondLast = 0, last = nums[1];
    for(int i=2; i<n; i++){
        int op1 = nums[i] + secondLast;
        secondLast = last;
        last = max(last,op1);
    }
    int val1 = last;
    int secondLast = 0, last = nums[0];
        for(int i=1; i<n-1; i++){
        int op1 = nums[i] + secondLast;
        secondLast = last;
        last = max(last,op1);
    }
    return max(val1,last);
}