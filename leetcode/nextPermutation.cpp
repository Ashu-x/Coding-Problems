void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = n-2;
    while(pivot >=0 && nums[pivot] >= nums[pivot+1]){
        pivot--;
    }
    if(pivot>=0){
        for(int i=n-1; i>=pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i] , nums[pivot]);
                break;
            }
        }
    }
    reverse(nums.begin() + pivot+1 , nums.end() );
}