// Problem Statement https://www.codechef.com/problems/DELSORTSUB?tab=statement
// You are given a binary string S of length N, consisting only of the characters 0 & 1. You are
// allowed to these Operation:
// Choose a sorted subsequence T from S, and delete all the characters of this subsequence from S simultaneously.

// Then, delete all characters at positions il, i2, ... , iK from S, and concatenate the remaining parts of
// the string.
// Your task is to determine the minimum number of operations required to make the string S balanced.

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    string s;
	    cin>>n>>s;
	    int cnt1 = 0, bal =0;
	    for(char ch:s){
	        if(ch == '0') bal++;
	        else{
	            if(bal > 0) bal--;
	            else cnt1++;
	        }
	    }
	    int cnt0 = bal;
	    if(cnt1 == 0 && cnt0 == 0) cout<<0<<endl;
	    else if(cnt1 > 0 && cnt0 > 0) cout<<2<<endl;
	    else cout<<1<<endl;
    }
}