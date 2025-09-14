void setZeroes(vector<vector<int>>& matrix) {
    // int colMark[m] => matrix[0][...]
    // int rowMark[n] => matrix[...][0]
    int col = 1;
    int n = matrix.size(), m = matrix[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(matrix[i][j] == 0){
                matrix[i][0] = 0;         // mark the ith row

                if(j != 0){
                    matrix[0][j] = 0;     // mark the jth col
                }
                else col = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][j] != 0){
                // check for row & col
                if(matrix[i][0] ==0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0){ 
        for(int j=0; j<m; j++) matrix[0][j] =0;
    }

    if(col == 0){
            for(int i=0; i<n; i++) matrix[i][0] = 0;
    }

}