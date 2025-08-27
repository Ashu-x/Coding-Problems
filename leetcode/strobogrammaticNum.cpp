bool isStrobogrammatic(string num) {
    int mp[10] = {0,1,-1,-1,-1,-1,9,-1,8,6};
    int left=0, right = num.size() -1 ;
    while(left <= right){
        int a = num[left] - '0';
        int b = num[right] - '0';
        if(mp[a] != b) return false;
        left++;
        right--;
    }
    return true;
}