bool canPossible(vector<int>& stalls, int dist, int k){
    int prevPlace = nums[0];
    int cows=1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i] - prevPlace >= dist){
            cows++;
            prevPlace = nums[i];
        }
        if(cows >= k) return ture;
    }
    return false;
}

int aggressiveCows(vector<int> stalls, int k){
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0] ;
    while(low<=high){
        int mid = (low+high)/2 ;
        if(canPossible(stalls , mid, k)){
            low = mid+1;
        }
        else high = mid-1 ;
    }
    return high;
}