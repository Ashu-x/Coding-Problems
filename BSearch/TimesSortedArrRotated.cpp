#include<bits/stdc++.h>
using namesapce std;

int check(int x){   // we write a check func will make some elements zeroes and some ones then we will find break point
    if(a[0] > a[x]) return 1;
    else return 0;
}
// arr[] = [9 ,  , 1]
int main(){
    int n,x;
    int arr[100010];
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>x;

    int low = 0, high = n-1;
    int ans=0;      //Defualt value is ans when all are zeroes
    while(low<=high){
        int mid = low + (high - low)/2 ;
        if(check(mid) == 1){
            ans = mid;
            high = mid -1;
        }
        else low = mid + 1;
    }
    cout<<ans<<endl;
    return 0;
}