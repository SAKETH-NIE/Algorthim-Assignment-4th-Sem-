#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

 using namespace std; 

const int INF = numeric_limits<int>::max();

class Graph {
public:
    Graph(int vertices);

    void addEdge(int from, int to, int weight);

    int tsp(int start);

private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;
};

Graph::Graph(int vertices) : numVertices(vertices), adjacencyMatrix(vertices, vector<int>(vertices, 0)) {}

void Graph::addEdge(int from, int to, int weight) {
    adjacencyMatrix[from][to] = weight;
}

int Graph::tsp(int start) {
    vector<int> notVisited;
    for (int i = 0; i < numVertices; ++i) {
        if (i != start) {
            notVisited.push_back(i);
        }
    }

    int minPathCost = INF;

    do {
        int currentPathCost = 0;
        int currentVertex = start;
        for (int nextVertex : notVisited) {
            currentPathCost += adjacencyMatrix[currentVertex][nextVertex];
            currentVertex = nextVertex;
        }
        currentPathCost += adjacencyMatrix[currentVertex][start]; // Return to starting vertex

        minPathCost = min(minPathCost, currentPathCost);

    } while (next_permutation(notVisited.begin(), notVisited.end()));

    return minPathCost;
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph graph(numVertices);

    int from, to, weight;
    cout << "Enter the edges (from to weight), type -1 -1 -1 to stop: " << endl;
    while (true) {
        cin >> from >> to >> weight;
        if (from == -1 && to == -1 && weight == -1) {
            break;
        }
        graph.addEdge(from, to, weight);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    int minCost = graph.tsp(startVertex);
    cout << "Minimum TSP cost: " << minCost << endl;

    return 0;
}