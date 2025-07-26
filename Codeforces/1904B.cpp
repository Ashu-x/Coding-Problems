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
// typedef pair<int, int> pii;
// typedef pair<int, int> pl;
// typedef vector<int> vi;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef vector<ld> vld;
// typedef vector<double> vd;

class comp
{
public:
    bool operator()(const pair<int,pair<int,int>>  a, const pair<int,pair<int,int>>  b)
    {
        return a.first <= b.first;
    }
};

int dir_c[] = {-1, 0, 1, 0};
int dir_r[] = {0, 1, 0, -1};
typedef priority_queue<pair<int ,pair<int,int>> , vector<pair<int,pair<int,int>>>> mxpqc;
const long long  mod = 1000000007;
// instead of using ceil(double(a)/b) for rounding up use (a+(b-1))/b

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("Error.txt", "w", stderr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    fastio();
    int t = 1;
    cin>>t;
    rep(i, 1, t + 1)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
void solve() {
  int n;
  cin>>n;
  vector<pair<int,int>> a(n);
  rep(i,0,n) {
    cin>>a[i].first;
    a[i].second = i;
  }
  vector<int> ans(n), presum(n);
  sort(a.begin(),a.end());
  presum[0] = a[0].first;

  rep(i,1,n){
    presum[i] = a[i].first + presum[i-1];
  }
  for(int i=0; i<n; i++){

    int j=i,found=i;
    while(j<n){
        pair<int,int> temp={presum[j]+1 , INT_MIN} ;
        int it = lower_bound(a.begin(), a.end(), temp) - a.begin();
        it--;
        if(it==j) break;
        found += it-j;
        j=it;
    }
    ans[a[i].second] = found;
  }
  for(int i:ans) cout<<i<<" ";
  cout<<endl;
}

// PROBLEM LINK -> https://codeforces.com/problemset/problem/1904/B