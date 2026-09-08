```cpp

    long long countGood(vector<int>& nums, int k) {
        long long ans =0;
        int i=0,j=0, n = nums.size();
        long long pairs = 0;
        unordered_map<int,int> mp;

        while(j<n){
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            while(pairs >= k){
                ans += n - j;
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }

            j++;
        }
        return ans;
    }
```
### Problem :Given an integer array nums and an integer k, return the number of good subarrays of nums. A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
