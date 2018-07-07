#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

using namespace std;

const int INF = (int) 1e10;
const int maxn = (int) 1e5;

int V, E, s;
vector<vii> adjList;
vi dist;
priority_queue<ii, vector<ii>, greater<ii>> pq;

int main(){
    cin >> V >> E >> s;

    adjList.assign(V, vii());
    dist.assign(V, INF); 
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v>> w;
        adjList[u].push_back(ii(v, w));
    }
    dist[s] = 0;
    pq.push(ii(0, s));

    while(!pq.empty()){
        auto front = pq.top(); pq.pop();
        int d = front.first; int u = front.second;
        // if this newly added relaxed edge is not good enough, simply ignore it.
        if(d > dist[u]) continue;
    
        // we see if we can use this new edge to relax its neighbors
        for(int i = 0; i < adjList[u].size(); i++){
            auto nb = adjList[u][i];
            int v = nb.first; int w = nb.second;
            // once we are able to relax it, we update the new node and put it into the pq
            // because we want to make sure that the new node can relax its neighbors.
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v)); 
            }
        }   
    }

    for(int i = 0; i < V; i++){
        printf("distance from source to %d is %d\n", i, dist[i]);
    }   

    return 0;
}