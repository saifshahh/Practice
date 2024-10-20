#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<char>> &forest, int x, int y, int n, int m){

    if (x < 0 || y < 0 || x >= n || y >= m || forest[x][y] != 'T'){
        return 0;
    }

    forest[x][y] = 'W';

    int size = 1; 
    size += dfs(forest, x + 1, y, n, m);  
    size += dfs(forest, x - 1, y, n, m);
    size += dfs(forest, x, y + 1, n, m);  
    size += dfs(forest, x, y - 1, n, m);  

    return size;
}

int LF(vector<vector<char>> &forest){
    int n = forest.size();
    int m = forest[0].size();
    int fMax = 0;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(forest[i][j] == 'T'){
                int size = dfs(forest, i, j, n, m);
                fMax = max(fMax, size);
            }
        }
    }
    return fMax;
}

int main() {
    vector<vector<char>> forest = {
        {'T', 'T', 'W', 'W', 'T'},
        {'T', 'W', 'W', 'T', 'T'},
        {'W', 'W', 'T', 'T', 'W'},
        {'W', 'T', 'T', 'T', 'T'},
        {'T', 'T', 'W', 'W', 'T'}
    };
    cout << LF(forest) << endl;
}
