int rotten(vector<vector<int>>&grid){
        int m = grid.size(), n = grid[0].size();
        int minutes = 0 , fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        int dx[4] = {0,1,-1,0};
        int dy[4] = {1,0,0,-1};
        while(!q.empty() && fresh > 0 ){
            int sz = q.size();
            while(sz--){ 
              // SIZE IS NOT UPDATING WHILE PUSHING NEW ORAGNES
                auto [x,y] = q.front(); q.pop();
                for(int r = 0; r<4; r++){
                  //GETTING newX, newY
                    int nx = x + dx[r];
                    int ny = y + dy[r];
                    if(nx < m && nx >= 0 && ny<n && ny >= 0 &&
                      grid[nx][ny] == 1){
                        grid[nx][ny] = 2; 
                        //make it rotten and push in que
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
            minutes++; 
          //after all current rotten orange covered i.e curr lvl completed min inc
        }
        return (fresh == 0 ? minutes : -1); 
}
// This is a multi-source BFS shortest-time problem.
Approach
->Push all initial rotten oranges into the queue.
->Count total fresh oranges.
->BFS level by level:
  ->For each rotten orange, rot its neighbors
  ->Newly rotten oranges go into the queue
->Each BFS level = 1 minute
->Stop when queue is empty
