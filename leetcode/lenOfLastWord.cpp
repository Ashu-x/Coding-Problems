int lengthOfLastWord(string s) {
        int n= s.length();
        bool f = (s[n-1] == ' ' ? true : false) ;
        int cnt=0;
        for(int i=n-1;  i>=0; i--){
            if(s[i] == ' ' && cnt !=0 ){
                break;
            }
            else if(s[i] != ' ') cnt++;
        }
        return cnt;
}
