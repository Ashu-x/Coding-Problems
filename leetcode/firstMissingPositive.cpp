int firstMissingPositive(vector<int>& nums) {
        int n=nums.size() ;
        for(int i=0; i<n; i++){
            if(nums[i] < 0) nums[i] = 0;
        }
        for(int i=0; i<n; i++){         // making places -ve to indicate ele of that place exist in array
            int ele = abs(nums[i]); 
            if(ele > 0 && ele <=n){
                if(nums[ele-1] == 0) nums[ele -1] = (-1)*(n+1) ; 
                else if(nums[ele-1] > 0) nums[ele-1] *= -1 ;        // if some ele is +ve mark its place -ve
            }
        }
        for(int i=1; i<=n; i++){
            if(nums[i-1] >= 0) return i;
                //if we found ele > n if wouldn't be -ve ise so w returing i(that place)
        }
        return n+1;
}
//FINDING SMALLEST POSITIVE INT not exist in unsorted array
