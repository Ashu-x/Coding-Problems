void helper(vector<int>& nums, int l, int r){
    while(l<r){
        swap(nums[l],nums[r]);
        l++;
        r--;
    }
}
// INPLACE ALGO via REAVERSAL OF ARRAY
void rotate(vector<int>& nums, int k) { 
        int n = nums.size();
        k = k%n ;
        helper(nums,0,n-1);
        helper(nums,0,k-1);
        helper(nums,k,n-1);
}

// GCD METHOD
void rotate(vector<int>& nums, int k){
    int n = nums.size();
    k%= n;
    int gcd = __gcd(n,k);
    for(int i=0; i<gcd; i++){
        int left = i;
        int currEle = nums[left];
        do{
            int nextIdx = (currEle+d)%n ;
            int nextEle = nums[nextIdx];

            nums[nextIdx] = currEle;
            left = nextIdx;
        } while(left  != i);
    }
}