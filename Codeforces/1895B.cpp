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
        cin >> n;
 
        vector<int> second_elements;
        int lowest_first_minimum = INT_MAX;
 
        for (int i = 0; i < n; i++) // n
        {
            int m;
            cin >> m;
            vector<int> a(m);
            for (auto &x : a) // m
                cin >> x;
            
            sort(a.begin(), a.end()); // mlogm
            
            second_elements.push_back(a[1]);
            lowest_first_minimum = min(lowest_first_minimum, a[0]);
        }
 
        sort(second_elements.begin(), second_elements.end());
 
        int sum_of_second_elements = accumulate(second_elements.begin(), second_elements.end(), 0LL);
        int lowest_second_minimum = second_elements[0];
 
        int ans = lowest_first_minimum + sum_of_second_elements - lowest_second_minimum;
        cout << ans << endl;
}
// https://codeforces.com/contest/1859/problem/B