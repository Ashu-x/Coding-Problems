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

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    int sum = -1;
    for(int i=0; i<n; i++){
        if(b[i] != -1){
            if(sum == -1) sum = a[i] + b[i];
                if(sum != a[i] + b[i]){
                    cout<<0<<endl;
                    return ;
                } 
            }
    }
    if(sum == -1){
      sort(a,a+n);
      cout<< (a[0] + k - a[n-1]) + 1 <<endl;
      return ;
    }
    rep(i,0,n){
        if(a[i] > sum || a[i] + k < sum){
            cout<<0<<endl;
            return ;
        }
    }
    out(1);
}
// PROBLEM LINK-> https://codeforces.com/problemset/problem/2106/C