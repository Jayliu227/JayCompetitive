#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

using namespace std;

const int maxn = (int) 1e5;
int n, e, mst_cost;

vector<vii> adjList;
priority_queue<ii> pq;
vi taken;
       
void process(int vtx){
	taken[vtx] = 1;
	for(int j = 0; j < adjList[vtx].size(); j++){
		ii v = adjList[vtx][j];
		if(!taken[v.first]){
			pq.push(ii(-v.second, -v.first));
		}
	}
}

int main(){
	cin >> n >> e;
	for(int i = 0; i < n; i++){
		adjList.push_back(vii());
	}

	for(int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adjList[a].push_back(make_pair(b,c));
		adjList[b].push_back(make_pair(a,c));
	}
	
	/*
	for(int i = 0; i < n; i++){
		auto nei = adjList[i];
		for(auto u : nei){
			cout << i << " " << u.first << " : " << u.second << endl;
		}
	}*/

	taken.assign(n, 0);
	process(0);
    mst_cost = 0;   

    while(!pq.empty()){
    	ii front = pq.top(); pq.pop();
		int u = -front.second;
		int w = -front.first;
		if(!taken[u]){
			mst_cost += w;
			process(u);
		}    
    }
   
	cout << "mst: " << mst_cost <<'\n';

	return 0;
}