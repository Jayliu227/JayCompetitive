#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

using namespace std;

const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e5;

int V, E, s;
vector<vii> adjList;

int main(){
    cin >> V >> E >> s;
    for(int i = 0; i < V; i++){
        adjList.push_back(vii());
    }

    for(int i = 0; i < E; i++){ 
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(ii(v,w));  
    }
    /*
    for(int i = 0; i < V; i++){
        for(int j = 0; j < adjList[i].size(); j++){
            cout << i << " " << adjList[i][j].first << " " << adjList[i][j].second << endl;
        }
    }*/

    int dist[V];
    for(int i = 0; i < V; i++) dist[i] = INF;

    dist[s] = 0;
    /*
    for(int i = 0; i < V - 1; i++){
        for(int u = 0; u < V; u++){
            for(int j = 0; j < adjList[u].size(); j++){
                ii v = adjList[u][j];
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
                //cout << dist[v.first] << " " <<dist[u] << '\n';
                //cout << u <<  " " << v.first << " " << dist[v.first] << '\n';             
            }
        }
    }
    */
    for(int k = 0; k < V - 1; k++){
        for(int u = 0; u < V; u++){
            for(int v = 0; v < adjList[u].size(); v++){
                auto edge = adjList[u][v];
                dist[edge.first] = min(dist[edge.first], dist[u] + edge.second);
            }
        }
    }
    
    for(int i = 0; i < V; i++){
        printf("source %d to %d is: %d\n", s, i, dist[i]);
    }
    
    return 0;
}