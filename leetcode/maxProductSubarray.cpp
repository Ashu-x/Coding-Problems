// FIRST APPROACH USING PREFIX AND SUFFIX
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1, suf = 1 , ans = INT_MIN;
    for(int i=0; i<n; i++){
        if(pre ==0 ) pre = 1;
        if(suf == 0) suf =1 ;

        pre = pre*nums[i];
        suf = suf*nums[n-i-1];
        ans = max(ans, max(pre,suf));

    }
    return ans;
}

// SECOND APPROACH USIGN MODIFIED KADANE'S ALGO
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MIN , minProd = nums[0] , maxProd = nums[0];
    for(int i=1; i<n; i++){
        if(nums[i] < 0){
            swap(minProd,maxProd);
        }
        minProd = min(nums[i] , minProd*nums[i]);
        maxProd = max(nums[i] , maxProd*nums[i]);
        ans = max(ans, maxProd);
    }
    return ans;
}

