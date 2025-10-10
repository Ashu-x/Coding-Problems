#include <bits/stdc++.h>
using namespace std;

int main() {
	// This approach , mp represents how many(mp[i]) elements are getting 0 by having some 'i' shifts.
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>n>>m;
	    int a[n];
	    long long totalSum =0;
	    int mp[m] ={0} ;
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	        totalSum += a[i];
	        mp[ (m-a[i])%m ]++;
	    }

	    long long currSum = totalSum;   // for zeroth(mp[0]) shift we have currsum as totalSum
	    for(int i=1; i<m; i++){
	        currSum += n;                   //we are adding n times 1 to each element of Array
	        currSum = currSum - (mp[i]*m);  //substracting of count(mp[i]) of elements on ith shift, 
                                            // and they are getting wrap around i.e. substracting m
	        totalSum = min(currSum, totalSum);
	    }
	    cout<<totalSum<<endl;
	}
}
// https://www.codechef.com/problems/MINSMODM?tab=statement