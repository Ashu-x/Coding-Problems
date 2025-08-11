int sortPermutation(vector<int>& nums) {
    int n=nums.size();
    int ans = (1<<30) - 1 ;
    bool f = true;
    for(int i=0; i<n; i++){
        if(nums[i] != i){ 
            ans = (ans & nums[i]);
            cout<<ans<<"~";
            f= false;
        }
    }
    if(f) return 0;
    else return ans;
}