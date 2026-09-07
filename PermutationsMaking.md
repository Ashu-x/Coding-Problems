# Permutations
## Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

---

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```
---

```cpp
void perms(vector<int> &curr, vector<int>& nums, vector<vector<int>> &ans, vector<bool> &visited){
        if(curr.size() == nums.size()) {
           ans.push_back(curr);
           return ;
        }

        for(int i=0 ; i<nums.size(); i++){
            if(!visited[i]){
                curr.push_back(nums[i]);
                visited[i] = true;

                perms(curr, nums, ans, visited);

                curr.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> curr ;
        vector<bool> visited(nums.size(), false) ; 
        perms(curr, nums, ans, visited);
        return ans;
    }
};
```
---
