#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void addEdge(unordered_map<int, vector<int>>& tree, int parent, int child) {
    tree[parent].push_back(child); 
    tree[child].push_back(parent);  
}

void bfs(int start, unordered_map<int, vector<int>>& tree) {
    unordered_map<int, bool> visited;  
    queue<int> q; 
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int levelSize = q.size(); 
        vector<int> currentLevel;
        for (int i = 0; i < levelSize; i++) {
            int current = q.front();
            q.pop();
            currentLevel.push_back(current);
            
            for (int neighbor : tree[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        for (int i = 0; i < currentLevel.size(); i++) {
            if (i > 0) cout << " ";  
            cout << currentLevel[i];
        }
        cout << endl;  
    }
}

int main() {
    unordered_map<int, vector<int>> tree;  

    int n, useless;
    cin >> n;       
    cin >> useless; 

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(tree, x, y);
    }
    
    int start;
    cin >> start;   

    bfs(start, tree);

    return 0;
}