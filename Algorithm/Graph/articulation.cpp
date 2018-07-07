#include<bits/stdc++.h>

#define UNVISITED -1

using namespace std;

const int maxn = 100;
int n, e;
struct vertex{  
    vector<int> neighbors;
};

int dfsNumberCounter;
int dfs_num[maxn];
int dfs_low[maxn];
int dfs_parent[maxn];
int art_vertex[maxn];
vertex vertices[maxn];

int dfsRoot;
int rootChild;

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int j = 0; j < vertices[u].neighbors.size(); j++){
        int v = vertices[u].neighbors[j];
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            if(u == dfsRoot) rootChild++;

            articulationPointAndBridge(v);

            if(dfs_low[v] >= dfs_num[u]){
                art_vertex[u] = true;
            }
            if(dfs_low[v] > dfs_num[u]){
                printf("Edge (%d, %d) is a bridge\n", u, v);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if(v != dfs_parent[u]){
            // back edge here
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    } 

}

int main(){
    cin >> n >> e;
    for(int i = 0; i < n; i++){
        vertices[i] = vertex();      
    }
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        vertices[a].neighbors.push_back(b);
        vertices[b].neighbors.push_back(a);
    }       

    dfsNumberCounter = 0;
    for(int i = 0; i < n; i++){
        dfs_num[i] = UNVISITED;
        dfs_low[i] = 0;     
        dfs_parent[i] = -1;
        art_vertex[i] = 0;
    }

    printf("Bridges:\n");
    for(int i = 0; i < n; i++){
        if(dfs_num[i] == UNVISITED){
            dfsRoot = i;
            rootChild = 0;
            articulationPointAndBridge(i);
            art_vertex[dfsRoot] = (rootChild > 1);
        }   
    }

    printf("Articulation Points:\n");

    for(int i = 0; i < n; i++){
        if(art_vertex[i] == true)
            printf(" Vertex %d\n", i);
    }

    return 0;
}