#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(void);
#define endl '\n'
#define int long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define input(arr, i, n) rep(j, i, n) cin >> arr[j];
#define outDouble(x, y) cout << fixed << setprecision(y) << x
#define maxn 1000001
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);  cout.tie(NULL)
#define rep(i, j, n) for (int i = j; i < n; i++)
#define pre(i, j, n) for (int i = j; i >= n; i--)
#define input(arr, i, n) rep(j, i, n) cin >> arr[j];
#define out(a) cout << a << '\n';
#define all(arr) arr.begin(), arr.end()

signed main()
{

    int t =1;
    // cin>>t;
    while(t--)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}


void solve() {
    int n;
    cin>>n;
    int a[n] , cnt[100001] ={0}, ans[100001]={0};
    rep(i,0,n) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    
    ans[0] = 0;
    ans[1] = cnt[1];
    for(int i=2; i<100001; i++){
        ans[i] = max((cnt[i]*i) + ans[i-2] , ans[i-1]);
   }
    cout<<ans[100000]<<endl;
}