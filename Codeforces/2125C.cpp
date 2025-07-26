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
bool isValid(int num){
    return num%2 && num%3 && num%5 && num%7 ;
}

int count(int num){
    int count=0;
    for(int i=0; i<num; i++){
        if(isValid(i)) count++;
    }
    return count;
}

int get(int n){
    return (n/210)*count(210) + count(n%210);
}

void solve() {
    int l,r;
    cin>>l>>r;
    cout<<get(r+1) - get(l)<<endl;
}
// https://codeforces.com/problemset/problem/2125/C