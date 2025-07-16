int maxChunksToSorted(vector<int>& arr) {
        int cnt=0, k=0,sum=0 ;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            k += i;
            if( sum == k ){
                cnt++;
            }
        }
        return cnt;
}