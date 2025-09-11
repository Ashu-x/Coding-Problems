int maxProfit(vector<int>&nums){
int profit= 0;
int mini=nums[0];
for(int i=1; i<n; i++){
profit = max(profit, nums[i] - mini);
mini = min(mini , nums[i]);
}
return profit;
}