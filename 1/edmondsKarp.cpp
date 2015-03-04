#include "stdio.h"
#include "stdlib.h"
#include <vector>

int edmondsKarp() {
    int fmax = 0;
    return fmax;
}

void printTable(int ** T, int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j){
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

int main() {
    printf("%d\n", edmondsKarp());
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    printf("%d\n", n);
    printf("%d\n", m);
    printf("%d\n", s);
    printf("%d\n", t);
   
    int ** network = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++){
        network[i] = (int *) malloc(sizeof(int) *n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            network[i][j] = 0; 
        }
    }
    int u, v, f;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &f);
        network[u][v] = f;
        network[v][u] = f;
    }
    printTable(network, n);
}

