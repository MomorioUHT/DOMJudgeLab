#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createGraph(int n) {
    vector<vector<int>> graph(n, vector<int>(n, 0));
    return graph;
}

void checkVertexConnections(const vector<vector<int>>& graph, int vertex, const vector<pair<int, int>>& edgeList) {
    for (int i = 0; i < vertex; i++) {
        int edgeCount = 0;
        vector<int> connectedEdges;

        for (int j = 0; j < edgeList.size(); j++) {
            if (edgeList[j].first == i + 1 || edgeList[j].second == i + 1) {
                edgeCount++;
                connectedEdges.push_back(j + 1); 
            }
        }

        cout << "v" << i + 1 << ": "; 
        if (edgeCount == 0) {
            cout << "Isolated" << endl;
        } else if (edgeCount == 1) {
            cout << "Impasse coming from e" << connectedEdges[0] << endl;
        } else if (edgeCount == 2) {
            cout << "Corner connecting e" << connectedEdges[0] << " e" << connectedEdges[1] << endl;
        } else if (edgeCount > 2) {
            cout << "Junction of";
            for (int k = 0; k < connectedEdges.size(); k++) {
                cout << " e" << connectedEdges[k];
            }
            cout << endl;
        }
    }
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;

    vector<vector<int>> grid = createGraph(vertex);
    vector<pair<int, int>> edgeList(edge);

    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        edgeList[i] = {u, v};

        grid[u - 1][v - 1] = 1;
        grid[v - 1][u - 1] = 1;
    }

    checkVertexConnections(grid, vertex, edgeList);

    return 0;
}
