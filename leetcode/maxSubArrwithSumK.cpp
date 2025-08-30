int longestSubarrayWithSumK(vector<int>& a, long long k){
    unordered_map<long long ,int> mp;   
            //UNORDERED_MAP TAKES O(n) time for inserting and searching IF CONSTRAINTS ARE SUCH THAT MANY COLLISIONS OCCURS
            // THEN USE ORDER MAP -> O(logn)
    
    long long sum=0;
    int maxLen =0;
    int presum
    for(int i=0; i<a.size(); i++){
        sum += a[i];

        if(sum == k){
            maxLen = max(maxLen , i+1);
        }

        else if(mp.find(sum-k) != mp.end()){
            int len = i- mp[sum-k];
            maxLen = max(maxLen, len);
        }

        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return maxLen;
}
// Above code is optimal code which works for Array having negatives and zeroes.

// NOW FOR ONLY POSITVIE VALUES IN ARRAY => TWO POINTER APPROACH
int longestSubarrayWithSumK(vector<int> a, long long k){
    int i=0,j=0;
    long long sum=a[0];
    int maxLen=0;
    while(j<a.size()){
        while(i<=j && sum > k){
            sum -= a[i];
            i++;
        }
        if(sum == k) maxLen = max(maxLen, j-i+1) ;

        j++;
        if(j<n) sum += a[j];
    }
    return maxLen;
}