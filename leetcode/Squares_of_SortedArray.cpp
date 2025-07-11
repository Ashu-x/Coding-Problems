#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// LeetCode Solution Class
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1, k = n - 1;
        vector<int> ans(n, 0);
        while (k >= 0) {
            if (abs(nums[i]) <= abs(nums[j])) {
                ans[k] = nums[j] * nums[j];
                j--;
            } else {
                ans[k] = nums[i] * nums[i];
                i++;
            }
            k--;
        }
        return ans;
    }
};

// Optional: Simple test harness for local testing
int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    Solution sol;
    vector<int> result = sol.sortedSquares(nums);

    cout << "Output: ";
    for (int num : result) cout << num << " ";
    cout << endl; // Output: 0 1 9 16 100

    return 0;
}
