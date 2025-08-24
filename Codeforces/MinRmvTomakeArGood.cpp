#include<bits/stdc++.h>
using namespace std;
int minRemove(vector<int> &a , int k);


int minRemove(vector<int> &arr, int k){
        int n = arr.size();
    int count[k];
    for(int i=0; i<n; i++){
        if( arr[i] ==0) count[0]++;
        else{
            if(count[arr[i] - 1] > 0){
                count[arr[i] -1]--;
                count[arr[i]]++;
            }
        }
    }
    return n - (count[k-1]*k) ;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    int ans = minRemove(a,k);
    cout<<ans<<endl;
    return 0;
}