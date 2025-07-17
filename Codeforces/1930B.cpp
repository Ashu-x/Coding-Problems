#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      int l=1,r=n;
      for(int i=1; i<=n; i++){
        if(i%2){
          cout<<l<<" ";
          l++;
        }
        else{
          cout<<r<<" ";
          r--;
        }
      }cout<<endl;
    }
    return 0;
}
