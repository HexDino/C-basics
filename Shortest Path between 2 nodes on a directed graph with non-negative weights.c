#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100001
#define INF 100000000

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->edges = (Edge *)malloc(sizeof(Edge) * capacity);
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swapEdge(Edge *a, Edge *b) {
    Edge t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->edges[left].weight < minHeap->edges[smallest].weight) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->edges[right].weight < minHeap->edges[smallest].weight) {
        smallest = right;
    }

    if (smallest != idx) {
        swapEdge(&minHeap->edges[smallest], &minHeap->edges[idx]);
        minHeapify(minHeap, smallest);
    }
}

Edge extractMin(MinHeap *minHeap) {
    if (minHeap->size <= 0) {
        return (Edge){-1, 0};
    }
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->edges[0];
    }

    Edge root = minHeap->edges[0];
    minHeap->edges[0] = minHeap->edges[--minHeap->size];
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap *minHeap, int vertex, int weight) {
    int i = 0;
    for (; i < minHeap->size; ++i) {
        if (minHeap->edges[i].vertex == vertex) {
            minHeap->edges[i].weight = weight;
            break;
        }
    }
    while (i && minHeap->edges[(i - 1) / 2].weight > minHeap->edges[i].weight) {
        swapEdge(&minHeap->edges[i], &minHeap->edges[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insertMinHeap(MinHeap *minHeap, Edge edge) {
    if (minHeap->size == minHeap->capacity) {
        return;
    }
    minHeap->edges[minHeap->size] = edge;
    int i = minHeap->size;
    minHeap->size++;
    while (i && minHeap->edges[(i - 1) / 2].weight > minHeap->edges[i].weight) {
        swapEdge(&minHeap->edges[i], &minHeap->edges[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap *minHeap, int vertex) {
    for (int i = 0; i < minHeap->size; ++i) {
        if (minHeap->edges[i].vertex == vertex) {
            return 1;
        }
    }
    return 0;
}

void dijkstra(int **graph, int n, int src, int dest) {
    int dist[n + 1];
    MinHeap *minHeap = createMinHeap(n);

    for (int v = 1; v <= n; v++) {
        dist[v] = INF;
        insertMinHeap(minHeap, (Edge){v, dist[v]});
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    while (minHeap->size > 0) {
        Edge minEdge = extractMin(minHeap);
        int u = minEdge.vertex;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v++]) {
            if (graph[u][v] && isInMinHeap(minHeap, v)) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    decreaseKey(minHeap, v, newDist);
                }
            }
        }
    }
    }
    if (dist[dest] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[dest]);
    }

    free(minHeap->edges);
    free(minHeap);
}

int main() {
    int n, m, s, t;
    scanf("%d %d", &n, &m);

    // Initialize graph
    int **graph = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++) {
        graph[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    scanf("%d %d", &s, &t);
    dijkstra(graph, n, s, t);

    // Free memory
    for (int i = 1; i <= n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}