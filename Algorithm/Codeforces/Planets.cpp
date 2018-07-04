#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
map< pair<int,int>, int > delay;
vector< vector< pair<int, int> > > adj;
vector<int> dist;

void solve(){
    dist.assign(n, INF);
    priority_queue< pii, vector<pii>, greater<pii> > q;

    dist[0] = delay[make_pair(0, 0)];
    q.push(make_pair(dist[0], 0));
    while(!q.empty()){
        int cur = q.top().second;
        int d = q.top().first;
        q.pop();

        if(d != dist[cur])
            continue;

        for(int i = 0; i < adj[cur].size(); i++){
            pii edge = adj[cur][i];
            int to = edge.first;
            int weight = edge.second;
            
            if(to != n - 1){
                weight += delay[make_pair(to, dist[cur] + weight)];           
            }

            if(dist[cur] + weight < dist[to]){
                dist[to] = dist[cur] + weight;
                q.push(make_pair(dist[to], to));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    adj.resize(n);
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int num;

    for(int i = 0; i < n; i++){
        cin >> num;
        vector<int> temp(num);
        for(int j = 0; j < num; j++){
            cin >> temp[j];
        }
        
        if(num > 0){
            delay[make_pair(i, temp[num - 1])] = 1;
        }

        for(int j = num - 1; j >= 1; j--){
            if(temp[j - 1] + 1 == temp[j]){
                delay[make_pair(i, temp[j - 1])] = delay[make_pair(i, temp[j])] + 1;
            }else{
                delay[make_pair(i, temp[j - 1])] = 1;
            }
        }
    }

    solve();

    if(dist[n - 1] == INF){
        cout << -1 << endl;
    }else{
        cout << dist[n - 1] << endl;
    }
    return 0;
}