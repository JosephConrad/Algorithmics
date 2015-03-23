#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

int const MAX = 1000000;

void printTable(int ** T, int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j){
            printf("%d\t", T[i][j]);
        }
        printf("\n");
    }
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
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


void floydWarshall(int ** network, int n, int m, int s, int t) {
    int ** D = matrix(n);
    REP(i, n) {
        REP(j, n) {
            D[i][j] =  MAX;
        }
        D[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (network[i][j] != 0)
                D[i][j] = network[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                    D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    printf("SHORTEST PATHS BETWEEN VERTICES:\n");
    printTable(D, n);
}

int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);

    int ** network = matrix(n);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        network[u][v] = w;
        network[v][u] = w;
    }

    printf("INPUT GRAPH:\n");
    printTable(network, n);
    floydWarshall(network, n, m, s, t);
}

