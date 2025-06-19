#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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
// Convert character label to index
int getVertexIndex(char label) {
    return label - 'A';
}
// Recursive DFS function to detect cycle
bool dfsDetectCycle(int current, vector<bool>& visited, vector<bool>& recursionStack, vector<int>& path) {
    visited[current] = true;
    recursionStack[current] = true;
    path.push_back(current);
    cout << "Push: " << vertexLabels[current] << endl;
    for (int neighbor = 0; neighbor < NUM_VERTICES; ++neighbor) {
        if (adjacencyMatrix[current][neighbor]) {
            cout << "Peek: " << vertexLabels[neighbor] << endl;
            if (!visited[neighbor]) {
                if (dfsDetectCycle(neighbor, visited, recursionStack, path))
                    return true;
            } else if (recursionStack[neighbor]) {
                cout << "Cycle Detected: ";
                for (int i : path) cout << vertexLabels[i] << " ";
                cout << vertexLabels[neighbor] << endl;
                return true;
            }
        }
    }
    cout << "Pop: " << vertexLabels[current] << endl;
    recursionStack[current] = false;
    path.pop_back();
    return false;
}

int main() {
    cout << "=== DFS Cycle Detection ===" << endl;
    // 🌟 Change the starting vertex letter here!
    char startVertex = 'D';
    int startIndex = getVertexIndex(startVertex);
    vector<bool> visited(NUM_VERTICES, false);
    vector<bool> recursionStack(NUM_VERTICES, false);
    vector<int> path;
    if (!dfsDetectCycle(startIndex, visited, recursionStack, path))
        cout << "No cycle detected using DFS.\n";
    return 0;
}
