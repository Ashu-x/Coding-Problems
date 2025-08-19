
    bool isvalid(vector<int> &mps1 , vector<int> & mps2){
            for(int i=0; i<26; i++){
                if(mps1[i] != mps2[i]) return false;
            }
            return true;
        }

    bool checkInclusion(string s1, string s2) {
        int window = s1.length();
        int n = s2.length();
        if(window > n) return false;
        vector<int> mp1(26,0) , mp2(26,0) ;
        for(char c:s1) mp1[c- 'a']++;

        int left =0, right =0;
        while(right<n){
            mp2[s2[j] - 'a']++;

            if(j--i + 1 == window){
                if(isvalid(mp1, mp2)) return true;
            }
            if(j-i + 1 < window) j++;
            else{
                mp2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }