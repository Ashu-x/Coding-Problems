## Print all paths to go from start of matrix to its End

```
cpp
void matrixPaths(int i, int j, int n, int m, vector<char> &path){
    if(i >= n || j >= m) return ;
    
    if(i == n -1 && j == m-1){
        for(char i:path) cout<<i<<" ";
        cout<<endl;
        return ;
    }
    //jump to right
    path.push_back('R'); 
    matrixPaths(i, j+1, n,m, path);
    path.pop_back(); //backtrack

    //jump down
    path.push_back('D');
    matrixPaths(i+1, j, n, m, path);
    path.pop_back();    //backtrack
}

//Visualisation -> https://share.gemini.google/p5IAYGkP93VX

int main() 
{
    vector<char> path;
    matrixPaths(3,4,0,0,path);
}
