## Print all Subsequences of array

```
cpp
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void allSubsequences(int i, const vector<int>& arr, vector<int>& path) {
    if (i == arr.size()) {
        for (int val : path) cout<<va<<" ";
        cout<<endl;
        return;
    }

    // Take element
    path.push_back(arr[i]);
    allSubsequences(i + 1, arr, path);
    path.pop_back();

    // Not take
    allSubsequences(i + 1, arr, path);
}

int main() {
    vector<int> arr = {1, 5, 10, 6};
    vector<int> path;
    allSubsequences(0, arr, path);
}
