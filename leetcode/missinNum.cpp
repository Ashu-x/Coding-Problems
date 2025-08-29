int missingNumber(vector<int>& nums) { //Using XOR
        int x1 =0,x2=0;
        int n= nums.size();
        for(int i:nums){
            x1 ^= i ;
            x2 = x2^(i+1);
        }
    return x1^x2 ;
}

//Using SUM
int missingNumber(vector<int>& nums){
    int n = nums.size();
    int sum=0, tSum = n*(n+1)/2 ;
    for(int i:nums) sum += i;
    return tSum - sum;
}