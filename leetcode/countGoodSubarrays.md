## PROBLEM: 
### Given an integer array nums and an integer k, return the number of good subarrays of nums. A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
---
### Approach
1. Use a sliding window from left to right.
2. Maintain a frequency map ```(freq)``` of numbers in the current window.
3. As we expand the right end of the window:
      - Each new number ```num``` contributes ```freq[num]``` new pairs to pairCount (since it can pair with each previous occurrence).
4. When ```pairCount >= k```, all subarrays starting at ```left``` and ending at or after ```right``` are valid.
      - Add ```nums.length - right``` to the count of good subarrays.
5. To try and minimize the window (while still satisfying the condition), move ```left``` forward and update the frequency and ```pairCount```.

```
cpp

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
