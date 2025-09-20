vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int> a;
    for(int i=0; i<grid.size(); i++)
        for(int j=0; j<grid[0].size(); j++)
            a.push_back(grid[i][j]);

    int xr=0, n = a.size();
    for(int i=0; i<n; i++){
        xr = (xr^a[i]);
        xr^= (i+1);
    }
    
    int rightMostBit = 0;
    while(1){
        if((xr & (1<<rightMostBit)) != 0){
            break;
        }
        rightMostBit++;
    }
    int zeroth = 0, oneth =0;
    for(int i=0; i<n; i++){
        if((a[i] & (1<<rightMostBit)) == 0){
            zeroth ^= a[i];
        }
        else oneth ^= a[i];

        if(((i+1)&(1<<rightMostBit)) == 0) {
            zeroth ^= (i+1);
        }
        else {
            oneth ^= (i+1);
        }
        
    }
    
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[i] == zeroth) cnt++;
    }
    if(cnt ==2) return {zeroth, oneth};
    else return {oneth, zeroth};
    
}