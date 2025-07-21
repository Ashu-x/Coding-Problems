int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i=0,j=0,m=0,ans=0;
        while(j<nums.size()){
            if(nums[i] >=left && nums[i]<=right){
                m = j-i + 1 ;
            }
            else if(nums[i] > right) {
                m=0;
                i = j+1;
            }
            ans += m;
            j++;
        }
        
        return ans;
    }