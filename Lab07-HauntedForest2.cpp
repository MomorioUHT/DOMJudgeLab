#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isHavingExit(vector<vector<int>> grid, int start, int end, int moveblock) {
    int rows = grid.size();
    int cols = grid[0].size();
    pair<int, int> startPos, endPos;
    
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == start) startPos = {i, j};
            if (grid[i][j] == end) endPos = {i, j};
        }
    }
    
    queue<pair<int, int>> q;
    q.push(startPos);
    
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[startPos.first][startPos.second] = true;
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        
        if (x == endPos.first && y == endPos.second) {
            return true;
        }
        
        for (int i = 0; i < directions.size(); i++) {
            int dx = directions[i].first;
            int dy = directions[i].second;
            int nx = x + dx;
            int ny = y + dy;
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && 
                (grid[nx][ny] == moveblock || grid[nx][ny] == end)) {
                
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    return false; 
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> grid(rows, vector<int>(cols));
    
    int start, end, moveblock;
    cin >> start >> end;
    cin >> moveblock;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }
    
    bool result = isHavingExit(grid, start, end, moveblock);
    
    if (result) {
        cout << "Yeah, There's The Way Out!" << endl;
    } else {
        cout << "Oh No! We're Trapped." << endl;
    }
    
    return 0;
}
