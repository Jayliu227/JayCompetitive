#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl

template<typename T> inline bool chkmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

vector<int> parent;
vector<int> ranks;

void init(int n){
    parent.resize(n + 1);
    ranks.resize(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        ranks[i] = 0;
    }
}

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

bool same(int i, int j){
    return find(i) == find(j);
}

void uni(int a, int b){
    int i = find(a);
    int j = find(b);
    if(i != j){
        if(ranks[i] < ranks[j]){
            swap(i, j);
        }
        parent[j] = i;
        if(ranks[i] == ranks[j]) ranks[i]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;    
    
    vector<pair<int, int>> build;
    vector<pair<int, int>> close;
    init(n);
    
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        if(same(u, v)){
            close.pb(make_pair(u, v));
        }else{
            uni(u, v);        
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(find(1) != find(i)){
            build.pb(make_pair(1, i));
            uni(1, i);
        }
    }
    
    cout << build.size() << endl;
    forn(k, build.size()){
        int u, v, i, j;
        i = close[k].fi;
        j = close[k].se;
        u = build[k].fi;
        v = build[k].se;
        cout << i << " " << j << " " << u << " " << v << endl;   
    }
    return 0;
}