vector<int> singleNumber(vector<int>& nums) {
    unsigned int xx=0;
    for(int i:nums){
        xx ^= i ;
    }
    int m = xx & (-xx) ;
    int x1=0,x2=0;
    for(int i:nums){
        if(i&m) x1 ^= i;
        else x2 ^= i;
    }
    return {x1,x2};
}