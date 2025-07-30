int firstMissingPositive(vector<int>& nums) {
        int n=nums.size() ;
        for(int i=0; i<n; i++){
            if(nums[i] < 0) nums[i] = 0;
        }
        for(int i=0; i<n; i++){
            int ele = abs(nums[i]);
            if(ele > 0 && ele <=n){
                if(nums[ele-1] == 0) nums[ele -1] = (-1)*(n+1) ;
                else if(nums[ele-1] > 0) nums[ele-1] *= -1 ;
            }
        }
        for(int i=1; i<=n; i++){
            if(nums[i-1] >= 0) return i;
        }
        return n+1;
}