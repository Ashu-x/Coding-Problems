bool validMountainArray(vector<int>& arr) {
        if(arr.size() <3) return false;
        int n = arr.size(), i=0;
        while(i+1<n && arr[i] < arr[i+1]){
            i++;
        }
        if(i ==0 || i==n - 1 ) return false;
        while(i+1<n && arr[i] > arr[i+1]) i++;
        return (i == n - 1);
}

// A Variation of it (climbing mountain from both sides) codeforces.com/contest/2143/problem/A
// You must form 1,2,…,n in strict increasing order. => 1, 2, …, k, n, n-1, …, k+1
// You can only remove numbers from either end of the array.
// It’s more like a two-pointer greedy check. 

void solve(){
    int l=0,r=n-1;
    for(int i=1; i<=n; i++){
        if(a[l] == i) l++;
        else if(a[r] == i) r--;
        else return false;
    }
    return true;
}
