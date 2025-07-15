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

    int t ;
    cin>>t;
    while(t--)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}


void solve() {
    int n,ans=0;
    cin >> n;
    string s;
    cin>>s;
    int a[26] = {0};
    for(int i=0; i<n; i++){
      if(a[s[i] - 'a'] == 0){
        a[s[i] -'a']++;
        ans += (n-i) ;
      }
    }
    out(ans);
}
