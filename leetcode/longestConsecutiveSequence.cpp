// better Aprroach by sorting
int longestConsecutive(vector<int>& nums){

    int n = nums.size();
    sort(nums.begin(), nums.end());
    int cnt=1 , longest=0;
    int lastEle = INT_MIN;
    for(int i=0; i<n; i++){
        if(nums[i] == lastEle + 1){
            cnt++;
            lastEle = nums[i];
        }
        else{
            cnt=1;
            lastEle = nums[i];
        }
        lnogest = max(longest , cnt);
    }
    return longest;
}

// Optimal Approach using SET
int longestConsecutive(vector<int>& nums){
    int n = nums.size();
    unordered_set<int> s(nums.begin(),nums.end());
    int ans=0,cnt=0;
    for(auto it:s){
        if(st.find(it-1) == s.end()){
            cnt =1;
            startElement = it ;
            while(s.find(it + 1) != s.end()){
                startElement++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}