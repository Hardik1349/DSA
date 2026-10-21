#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

void DFS(int graph[MAX][MAX], int visited[MAX], int vertex, int n) {


    visited[vertex] = 1;

    cout << vertex << " ";

    for (int i = 0; i < n; i++) {

        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(graph, visited, i, n);
        }
    }
}

void BFS(int graph[MAX][MAX], int n, int start) {

    int visited[MAX] = {0};

    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {

        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int i = 0; i < n; i++) {

            if (graph[vertex][i] == 1 && visited[i] == 0) {

                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {

    int n = 6;

    int graph[MAX][MAX] = {0};

    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    graph[1][4] = 1;
    graph[4][1] = 1;

    graph[2][5] = 1;
    graph[5][2] = 1;

    int start = 0;

    int visited[MAX] = {0};

    cout << "DFS traversal: ";
    DFS(graph, visited, start, n);

    cout << endl;

    cout << "BFS traversal: ";
    BFS(graph, n, start);

    cout << endl;

    return 0;
}