int divide(int dividend , int divisor){
    if(dividend == divisor) return 1;
    int sign = (dividend < 0)^(divisor < 0) ? -1 : 1 ;
    long ans=0;
    long a = abs((long)dividend);
    long b = abs((long)divisor);
    while(a >= b){
        int i=0;
        while(a >= (d<<(i+1))){
            i++;
        }
        b -= (a<<i);
        ans += (1<<i);
    }
    if(ans == (1<<31) - 1){
        return (1<<31);
    }
    if(ans == (1<<31) && sign>0) return INT_MAX;
    if(ans==(1<<31) && sign<0) return INT_MIN;

    return ans*sign ;
}