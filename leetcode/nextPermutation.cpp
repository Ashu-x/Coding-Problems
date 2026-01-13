void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = n-2;
    while(pivot >=0 && nums[pivot] >= nums[pivot+1]){
        pivot--;
    }
    if(pivot>=0){
        for(int i=n-1; i>=pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i] , nums[pivot]);
                break;
            }
        }
    }
    reverse(nums.begin() + pivot+1 , nums.end() );
}
Approach

We'll use a three-phase transformation strategy:

Find pivot: Scan from right to left to find the first position i where nums[i] < nums[i+1] (rightmost ascending pair)
Handle descending case: If no pivot exists (array is fully descending), reverse entire array to get smallest permutation
Reverse suffix: Reverse elements after pivot to prepare for finding swap candidate
Find swap candidate: Find smallest element after pivot that's larger than pivot element
Swap and complete: Swap pivot with candidate to get next permutation
This approach minimizes the lexicographic increase by choosing the smallest valid transformation.