class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int days){
        int cnt=0, cntOfBqs = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= days) cnt++;
            else{
                cntOfBqs += cnt/k;
                cnt = 0;
            }
        }
        cntOfBqs += cnt/k ;
        return cntOfBqs >= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mn = bloomDay[0], mx = bloomDay[0];
        for(int i:bloomDay){
            mn = min(mn, i);
            mx = max(mx, i);
        }
        int ans = 0;
        if(bloomDay.size() < 1LL*m * 1LL*k) return -1;
        while(mn<=mx){
            int mid = (mn+mx)/2;
            if(check(bloomDay,m,k,mid)){
                ans = mid;
                mx = mid - 1;
            }
            else mn = mid + 1;
        }
        return ans;
    }
};