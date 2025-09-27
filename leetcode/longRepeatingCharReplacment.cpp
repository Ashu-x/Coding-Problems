int characterReplacement(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    int maxFreq = 0;
    int mp[26];
    int l=0,r=0;
    while(r<n){
        mp[s[r] - 'A']++;
        maxFreq = max(maxFreq, mp[s[r] - 'A']);
        while((r-l+1) - maxFreq > k){
            mp[s[l] - 'A']--;
            l++;
        }
        maxLen = max(maxLen, (r-l+1));
        r++;
    }
    return maxLen;
}