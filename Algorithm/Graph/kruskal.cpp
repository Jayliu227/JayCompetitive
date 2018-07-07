#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>

using namespace std;

const int maxn = (int) 1e5;

struct UnionFind{
    vi sets;
    UnionFind(int v){
        for(int i = 0; i < v; i++){
            sets.push_back(i);
        }
    }

    int find(int a){
        while(a != sets[a]){
            a = sets[a];
        }
        return a;
    }

    bool inSame(int a, int b){
        return find(a) == find(b);          
    }

    void unionSet(int a, int b){    
        int ai = find(a);
        int bi = find(b);
        if(ai == bi) return;
        sets[ai] = bi;  
    } 
};

int n, mst_cost;
vector<pair<int, ii>> edges;

void mst(){
    UnionFind uf(n);
    for(int i = 0; i < n; i++){
        auto e = edges[i];
        int a = e.second.first;
        int b = e.second.second;
        if(!uf.inSame(a,b)){
            mst_cost += e.first;
            uf.unionSet(a,b);
        }       
    }
}

static bool comp(pair<int,ii>& a, pair<int,ii>& b){
    return a.first < b.first;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back(make_pair(c, make_pair(a,b)));
    }
    mst_cost = 0;
    sort(edges.begin(), edges.end());
    mst();
    cout << mst_cost << '\n';

    return 0;
}



