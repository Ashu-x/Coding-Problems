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
    cin>>t;
    while(t--)
    {
        // cout<<"Case #"<<": ";
        solve();
    }
    return 0;
}


void solve() {
    int cnt2=0, cnt1=0, sum=0,n,s;
    cin>>n>>s;
    int a[n] ;
    rep(i,0,n){
        cin>>a[i];
        sum += a[i];
        if(a[i] == 2) cnt2++;
        if(a[i] == 1) cnt1++;
    }
    int cnt0= n - (cnt1+cnt2);

    if(sum == s) {
        cout<<-1<<endl;
    }
    else if(s - sum > 1) {
        cout<<-1<<endl;
    }
    else{
        for(int i=0; i<cnt0; i++) cout<<0<<" ";
        for(int i=0; i<cnt2; i++) cout<<2<<" ";
        for(int i=0; i<cnt1; i++) cout<<1<<" ";
        cout<<endl;
    }

}