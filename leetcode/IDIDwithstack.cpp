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