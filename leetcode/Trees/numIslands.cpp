void dfs(int row, int col, vector<vector<int>>& visited , vector<vector<char>>& grid){
    int n = grid.size(), m = grid[0].size();
    visited[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int cnt=0;
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                cnt++;
                dfs(i, j, visited, grid);
            }
        }
    }
    return cnt;
}