int countsubArrXor_K(vector<int>& nums,int k){
    int cnt=0 , xo=0;;
    unordered_map<int,int> mp;
    mp[0]++;
    for(int i=0; i<nums.size(); i++){
        xo ^= nums[i];
        cnt += mp[xo^k];
        mp[xo]++;
    }
    return cnt;
}