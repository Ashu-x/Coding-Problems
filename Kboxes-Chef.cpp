// https://www.codechef.com/problems/KBOXES
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	      vector<int> a(n) , b(n);
	      unordered_map<int,int> mp;
	      for(int i=0; i<n; i++){
	           cin>>a[i];
	           mp[a[i]] = i;
	      }
	      for(int i=0; i<n; i++){
	          cin>>b[i];
	      }
	      
	      int sum=0;
	      vector<int> ans(n);
	      priority_queue<int, vector<int> , greater<int>> pq;
	      for(int i=1; i<=n; i++){
	          int idx = mp[i];
	          ans[idx] = sum ;
	          
            if(pq.size() < k){
              pq.push(b[idx]);
              sum += b[idx];
            }
            else if(pq.top() < b[idx] ){
                sum -= pq.top();
                pq.pop();
                pq.push(b[idx]);
                sum += b[idx];
            }
	      }
	      for(int i:ans){
	          cout<<i<<" ";
	      }
	      cout<<"\n";
	}
    return 0;
}
