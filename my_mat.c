#include "my_mat.h"
#include <stdio.h>
#include <limits.h>

#define MAX INT_MAX

void get_matrix (int ** matrix){
    // Receive input from the client
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    //check if matrix is simatric = undiracted graph!!!

}
// Function to find the shortest path between all pairs of vertices
int floydWarshall(int **graph, int src, int dest) {
    int dist[SIZE][SIZE];
    int i, j, k;

    // Initialize distance matrix
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i==j) dist[i][j]=0;
            else dist[i][j] = (graph[i][j] == 0) ? MAX : graph[i][j];
        }
    }

    // Compute shortest paths
    for (k = 0; k < SIZE; k++) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (dist[i][k] != MAX && dist[k][j] != MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    if (dist[src][dest]==0 || dist [src][dest]==MAX) return -1;
    return dist[src][dest];
}

int is_way (int ** mat, int s, int d){
    if (mat [s][d]!=0) return 1;
    int dis = floydWarshall(mat, s, d);
    if (dis == -1) return 0;
    if (dis>0 && dis < MAX) return 1;
    return 0;
}

int shortest_path_len(int ** m, int a, int b){
    int dis = floydWarshall(m, a, b);
    if (dis == MAX) return -1;
    if (dis == -1) return -1;
    if (dis>0 && dis < MAX) return dis;
    return 0;
}