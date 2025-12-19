string smallestNumber(string pattern) {
    stack<int> st;
    string ans ="";
    for(int i=0; i<=pattern.size(); i++){
        st.push(i+1);

        if(pattern[i] == 'I' || pattern.size() == i){
            while(!st.empty()){
                ans += to_string(st.top());
                st.pop();
            }
        }
    }
    return ans;
}

You are given a O-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.
Ip: pattern = "IIIDIDDD"
Op: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
