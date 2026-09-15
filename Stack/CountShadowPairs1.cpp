### Problem: 
You are given an integer array nums of length n.
A pair of indices (i, j) is called a shadow pair if all of the following conditions are satisfied:

- ```0 <= i < j < n```
- ```nums[i] < nums[j]```
- There does not exist an index k such that i < k < j and nums[k] < nums[i] < nums[j].

Return the total number of shadow pairs.

```cpp
    long long shadowPairs(vector<int>& nums) {

        long long ops = 0 ;

        stack<int> st ;
        int n = nums.size() ;
        unordered_map<int,int> mpp ;

        for ( int i = 0 ; i < n ; i++ ) {

            while ( !st.empty() && nums[i] < st.top() ) {

                mpp[st.top()]-- ;
                st.pop() ;

            }

            ops += ( st.size() - mpp[nums[i]] ) ;

            st.push(nums[i]) ;
            mpp[nums[i]]++ ;
            
        }
        return ops ;
    }
};
```

### Mysolution link 
(https://leetcode.com/problems/count-shadow-pairs-i/submissions/2142775521/)
```
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0;
        stack<int> st;
        int n = nums.size();
        st.push(nums[0]);

        for (int i = 1; i < n; i++) {
            int temp = 0;
            while (!st.empty() && st.top() > nums[i]) {
                int tp = st.top();
                st.pop();

                if (!st.empty()) {
                    if (st.top() == tp) {
                        temp++;
                    } else if (tp > st.top()) {
                        temp++;
                        ans += (st.size()) * temp;
                        temp = 0;
                    }
                }
            }
            st.push(nums[i]);
        }

        int temp = 0;
        while (st.size() > 1) {
            int tp = st.top();
            st.pop();

            if (st.top() == tp) {
                temp++;
            } else if (tp > st.top()) {
                temp++;
                ans += (st.size()) * temp;
                temp = 0;
            }
        }
        return ans;
    }
};```
