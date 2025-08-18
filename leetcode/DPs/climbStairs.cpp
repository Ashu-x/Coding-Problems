int climbStairs(int n) {
        vector<int> dp(n + 1 , 0 )  ;
        dp[0] = 1; 
        dp[1] = 2;  
        for(int i = 2 ; i<n;i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n-1] ; 
}

// Another Solution with O(1) Space

int climbStairs(int n) {
    int curr = 2,prev=1;
    if(n<2) return 1;
    
    for(int i=2; i<n; i++){
        curr = prev+curr;
        prev = curr - prev ;
    }
    return curr;
}