#include <iostream>
#include <vector>
using namespace std;

void pathFinder(vector<vector<int>> &maze, int x, int y, int n, string path, vector<string> &result){

    if(x == n-1 && y == n-1){
        result.push_back(path);
        return;
    }

    maze[x][y] = 0;

    if(x + 1 < n && maze[x + 1][y] == 1){
        pathFinder(maze, x + 1, y, n, path + "D", result);
    }

    if(y + 1 < n && maze[x][y + 1] == 1){
        pathFinder(maze, x, y + 1, n, path + "R", result);
    }

    if(x - 1 >= 0 && maze[x - 1][y] == 1){
        pathFinder(maze, x - 1, y, n, path + "U", result);
    }

    if(y - 1 >= 0 && maze[x][y - 1] == 1){
        pathFinder(maze, x, y - 1, n, path + "L", result);
    }

    maze[x][y] = 1;
}

vector<string> ratInMaze(vector<vector<int>> &maze){
    vector<string> result;
    int n = maze.size();
    if(maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return result; 
    pathFinder(maze, 0, 0, n, "", result);
    return result;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> result = ratInMaze(maze);
    for(string path : result) cout << path << " ";
}
