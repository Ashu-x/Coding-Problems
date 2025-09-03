int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    int i=1;
    sort(intervals.begin() , intervals.end());
    int cnt=0, prev = intervals[0][1];
    while(i<n){
        if(intervals[i][0] < prev ){
            prev = min(prev , intervals[i][1]);
            cnt++;
        }
        else prev = intervals[i][1];
        i++;
    }
    return cnt;
}