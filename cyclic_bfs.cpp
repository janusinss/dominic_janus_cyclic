#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int NUM_VERTICES = 7;
char vertexLabels[NUM_VERTICES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
// Adjacency matrix of the graph
int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES] = {
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};
// Convert vertex label to index
int getIndex(char label) {
    return label - 'A';
}
// BFS with control over starting vertex
bool bfsCycleFrom(char startVertexChar) {
    int startVertex = getIndex(startVertexChar);
    vector<bool> visited(NUM_VERTICES, false);
    vector<int> parent(NUM_VERTICES, -1);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Pop (BFS): " << vertexLabels[current] << endl;

        for (int i = 0; i < NUM_VERTICES; ++i) {
            if (adjacencyMatrix[current][i]) {
                if (!visited[i]) {
                    visited[i] = true;
                    parent[i] = current;
                    q.push(i);
                } else if (parent[current] != i) {
                    cout << "Cycle detected via: " << vertexLabels[current] << " -> " << vertexLabels[i] << endl;
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    cout << "=== BFS Cycle Detection (Controlled Start) ===" << endl;
    // Change this to control the starting vertex!
    char startChar = 'D';
    if (bfsCycleFrom(startChar))
        cout << "Cycle detected starting from " << startChar << " using BFS.\n";
    else
        cout << "No cycle detected starting from " << startChar << " using BFS.\n";
    return 0;
}
