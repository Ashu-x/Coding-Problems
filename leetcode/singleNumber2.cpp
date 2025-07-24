int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (int num : nums)
        sum += num >> i & 1;
      sum %= 3;
      ans |= (sum << i);
    }

    return ans;
}

// USING BUCKETS ONES AND TWOS
int singleNumber(vector<int>& nums) {
int ones=0,twos=0;
        for(int i:nums){
            ones = ((ones^i) & (~twos)) ;
            twos = ((twos^i) &(~ones));
        }
  return ones;
}