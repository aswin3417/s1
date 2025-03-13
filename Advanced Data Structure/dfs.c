#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void dfs(int adj[MAX][MAX], int V, int s, bool visited[MAX]) {
    int i;
    printf("%d ", s);
    visited[s] = true;

    for (i = 0; i <= V; i++) {
        if (adj[s][i] && !visited[i]) {
            dfs(adj, V, i, visited);
        }
    }
}

void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = adj[v][u] = 1;
}

int main() {
    int V, E, u, v, start ,i;
    int adj[MAX][MAX] = {0};
    bool visited[MAX] = {false};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS starting from vertex %d:\n", start);
    dfs(adj, V, start, visited);

    return 0;
}
              
