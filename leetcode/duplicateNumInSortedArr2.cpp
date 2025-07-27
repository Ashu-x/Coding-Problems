int removeDuplicates(vector<int>& nums) {
    int n=nums.size() , k=2,j=2;
    if(n <=2) return n;

    while(j<nums.size()){
        if(nums[k-2] != nums[j]){
            nums[k] = nums[j];
            k++;
        }
        j++;
    }
    return k;
}
