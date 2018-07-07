#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF (int)1e9

using namespace std;

const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e3;

int V, E;
int matrix[maxn][maxn];
int parent[maxn][maxn];

/*
REMARKS:
    if matrix[i][i] = INF, then we can test whether we have a cycle, negative cycle or find the cheapest cycle.
    if after the algorithm, it is no longer equal to INF, then there is a cycle, if it can be further reduced, then it is a negative cycle.
*/

void printRoad(int i, int j){
    if(i != j) printRoad(i, parent[i][j]);
    printf("-> %d", j);
}

int main(){
    cin >> V >> E;
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i == j)
                matrix[i][j] = INF;
            else
                matrix[i][j] = INF;
        }
    }

    

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w;
    }
    /*
    for(int i = 0 ; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << (matrix[i][j] == INF? -1 : matrix[i][j]) << " ";
        }
        cout << '\n';
    }*/

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            parent[i][j] = i;
        }
    }

    for(int k = 0; k < V; k++){
        for(int u = 0; u < V; u++){
            for(int v = 0; v < V; v++){
                matrix[u][v] = min(matrix[u][v], matrix[u][k] + matrix[k][v]);
                //if(matrix[u][k] + matrix[k][v] < matrix[u][v]){
                //  matrix[u][v] = matrix[u][k] + matrix[k][v];
                //  parent[u][v] = parent[k][v];
                //}
            }       
        }
    }

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("source %d to %d is: %d\n", i, j, matrix[i][j] == INF? - 1: matrix[i][j]);
            //if(matrix[i][j] != INF){
            //  printRoad(i, j); cout << '\n';
            //}
        }       
    }

    return 0;
}