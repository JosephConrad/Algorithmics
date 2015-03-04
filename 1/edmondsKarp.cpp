#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <limits.h>
#include <queue>

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

int ** matrix(int n) {
    int ** network = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++){
        network[i] = (int *) malloc(sizeof(int) *n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            network[i][j] = 0; 
        }
    }
    return network;
}



int edmondsKarp(int ** C, int n, int m, int s, int t) {
    int fmax = 0;
    int ** F = matrix(n);
    std::vector<int> P(n);
    std::vector<int> CFP(n);
    while (1) {
        for (int i = 0; i < n; i++) {
            P[i] = -1;
        }
        P[s] = -2;
        CFP[s] = INT_MAX;
        std::queue<int> Q;
        Q.push(s);
        int augmentingPath = 0;
        while ((!Q.empty()) && (!augmentingPath)) {
            int x= Q.front(); 
            Q.pop();
            //printf("x: %d\n", x);
            for (int y = 0; y < n; y++) {
                int cp = C[x][y] - F[x][y];
                //printf("cp: %d (x, %d), (y, %d)\n", cp, x, y);
                if ((cp == 0) || (P[y] != -1)) continue;
                P[y] = x;
                CFP[y] = std::min(CFP[x], cp);
                if (y == t) {
                    // augmenting path was found
                    fmax += CFP[t];
                    while (y != s) {
                        x = P[y];
                        F[x][y] += CFP[t];
                        F[y][x] += CFP[t];
                        y = x;
                        //printTable(F, n);
                    }
                    augmentingPath = 1;
                    break;
                }
                Q.push(y);
            } 
            if (augmentingPath) break;
        }
        if (!augmentingPath) break;
    }
    return fmax;
}


int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    //  printf("%d\n", n);
    //  printf("%d\n", m);
    //  printf("%d\n", s);
    //  printf("%d\n", t);
    
    int ** network = matrix(n);
 
    int u, v, f;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &f);
        network[u][v] = f;
        network[v][u] = f;
    }
    // printTable(network, n);
    
    printf("%d\n", edmondsKarp(network, n, m, s, t));
}

