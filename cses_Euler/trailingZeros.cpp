int fives(int num){
    if(num ==0) return 0;
    return num/5 + fives(num/5) ;
}
void solve() {
    int n;
    cin>>n;
    int ans =  fives(n);
    out(ans);
}
// jsut have to count how many mulltiple of 5s and for 25 there are 25 , for 125 three 5s
// SRC: https://www.geeksforgeeks.org/dsa/cses-solutions-trailing-zeros/
// Problem: 
// Your task is to calculate the number of trailing zeros in the factorial n!.
// For example, 20!=2432902008176640000 and it has 4 trailing zeros.
