#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    char value;
    Node* trueBranch;
    Node* falseBranch;
    Node(char val) : value(val), trueBranch(nullptr), falseBranch(nullptr) {}
};

void flipGraph(Node* root) {
    if (root == nullptr) return;
    
    Node* temp = root->trueBranch;
    root->trueBranch = root->falseBranch;
    root->falseBranch = temp;
    
    flipGraph(root->trueBranch);
    flipGraph(root->falseBranch);
}

string preOrder(Node* root) {
    if (root == nullptr) return "";
    return string(1, root->value) + preOrder(root->trueBranch) + preOrder(root->falseBranch);
}

string postOrder(Node* root) {
    if (root == nullptr) return "";
    return postOrder(root->trueBranch) + postOrder(root->falseBranch) + string(1, root->value);
}

string inOrder(Node* root) {
    if (root == nullptr) return "";
    return inOrder(root->trueBranch) + string(1, root->value) + inOrder(root->falseBranch);
}

string levelOrderTraversal(Node* root) {
    if (root == nullptr) return "";
    
    queue<Node*> q;
    string result = "";
    
    q.push(root);
    
    while (!q.empty()) {
        Node* currentNode = q.front();
        q.pop();
    
        result += currentNode->value;
        
        if (currentNode->trueBranch != nullptr) q.push(currentNode->trueBranch);
        if (currentNode->falseBranch != nullptr) q.push(currentNode->falseBranch);
    }
    
    return result;
}

Node* buildGraph(string expr) {
    stack<Node*> nodeStack;
    
    Node* root = nullptr;
    Node* current = nullptr;
    
    for (int i = 0; i < expr.length(); ++i) {
        if (isalpha(expr[i])) {
            Node* newNode = new Node(expr[i]);
            
            if (!nodeStack.empty()) {
                Node* topNode = nodeStack.top();
            
                if (topNode->trueBranch == nullptr) {
                    topNode->trueBranch = newNode;
                } else {
                    topNode->falseBranch = newNode;
                    nodeStack.pop();
                }
            }
            
            if (root == nullptr) root = newNode;
            current = newNode;
        }
        
        if (expr[i] == '?') nodeStack.push(current);
    }
    
    return root;
}

bool validCoord(int x, int y, int m, int n) {
    if (x>=0 && x<m && y>=0 && y<n)
        return true;
    return false;
}

bool findWord(int index, string word, vector<vector<char>> &grid,
              int x, int y, int dirX, int dirY) {
    
    if (index == word.length()) return true;
    
    if (validCoord(x, y, grid.size(), grid[0].size())
        && word[index] == grid[x][y])
        return findWord(index+1, word, grid, x+dirX, 
                        y+dirY, dirX, dirY);
        
    return false;
}

vector<vector<int>> searchWord(vector<vector<char>> grid, 
                               string word) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> ans;
    
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                if (findWord(0, word, grid, i, j, x[k], y[k])) {
                    ans.push_back({i, j});
                    break;
                }
            }
        }
    }
    
    return ans;
}

int main() {
    string ternaryExpression;
    cin >> ternaryExpression;

    string keyword;
    cin >> keyword;

    Node* graphRoot = buildGraph(ternaryExpression);
    flipGraph(graphRoot);

    string preOrderResult = preOrder(graphRoot);
    string postOrderResult = postOrder(graphRoot);
    string inOrderResult = inOrder(graphRoot);
    string levelOrderResult = levelOrderTraversal(graphRoot);

    vector<vector<char>> matrix;

    matrix.push_back(vector<char>(preOrderResult.begin(), preOrderResult.end()));
    matrix.push_back(vector<char>(postOrderResult.begin(), postOrderResult.end()));
    matrix.push_back(vector<char>(inOrderResult.begin(), inOrderResult.end()));
    matrix.push_back(vector<char>(levelOrderResult.begin(), levelOrderResult.end()));

    vector<vector<int>> positions = searchWord(matrix, keyword);

    string result = "";
    for (int i = 0; i < positions.size(); i++) {
        result += to_string(positions[i][0] + positions[i][1]);
    }
    
    cout << result << endl;
    
    return 0;
}
