vector<int> intersect(vector<int>& a, vector<int>& b){
    int i=0,j=0;
    vector<int> ans;
    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]) i++;
        else if(b[j] < a[i]) j++
        else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}