int reverseString(string &s){
    int i=0, j=s.size()-1;
    while(i<j){
        s[i] = s[i]^s[j];
        s[j] = s[j]^s[i];
        s[i] = s[i]^s[j];

        i++;
        j--;
    }
    return s;
}
//reverse(s.begin(), s.end()) => O(1) takes time
// AND using for(i->n) ans += s[i] create copy of ans everytime so O(N^2) space