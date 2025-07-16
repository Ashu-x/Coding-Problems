#include<bits/stdc++.h>
using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    // Write your code here
    int mn =0 , mx = length-1;
    vector<int> ans(length,0);
    for(int i=0; i<updates.size(); i++){
            mn = min(updates[i][0] , mn);
            mx = max(updates[i][1] , mx);
            ans[updates[i][0]] += updates[i][2] ;
            ans[updates[i][1]] += updates[i][2] ;
        }
        for(int i=mn+1; i<=mx; i++){
            ans[i] += ans[i-1] ;
        }
        return ans;
    }
int main(){
    int n = 6;
    vector<vector<int>> updates = {{1,3,2}, {2,4,3}, {0,2,-2}} ;

    vector<int> ans = getModifiedArray(n,updates);
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}