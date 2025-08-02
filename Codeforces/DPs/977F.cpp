#include <iostream>
#include <bits/stdc++.h>
using namespace std;

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("Error.txt", "w", stderr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    fastio();
    int t = 1;
    // cin>>t;
    rep(i, 1, t + 1)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
void solve() {
    int k=0, n;
    cin>>n;
    int a[n];
    int curr=0;
    map<int,int> dp;
    for(int i=0; i<n; i++){
        cin>>a[i];
        dp[a[i]] = max(dp[a[i]] , dp[a[i] - 1] + 1);

        if(k< dp[a[i]]){
            k = dp[a[i]];
            curr = a[i];
        }
    }
    cout<<k<<endl;
    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        if(curr == a[i]){
            curr--;
            ans.push_back(i+1);
        }
    }
    for(int i=k-1; i>=0; i--) cout<<ans[i]<<" ";
    cout<<endl;
}
