// 3824. Minimum K to Reduce Array Within Limit
// nonPositive(nums, k)=> min number of operations needed to make every element of nums non-positive. In one operation, you can choose an index i and reduce nums[i] by k.

// Return an integer denoting the minimum value of k such that nonPositive(nums, k) <= k2.

bool check(vector<int>&nums, long long mid){
        long long cnt = 0;
        for(int ele:nums){
            cnt += (ele + mid - 1)/mid ;
        }
        return (cnt <= mid);
    }
    
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        long long low = 1 , high = 1e9 ;
        long long ans = high;
        while(low<high){
           long long mid = low + (high - low)/2 ;
           if(check(nums, mid)){
               ans = mid ;
               high = mid ;
            }
            else low = mid + 1;
        }
       return (int)low;
    }
