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

const int maxn = (int) 1e6 + 1;
map<int, int> time_machine[maxn];
int op, t, target;
int qry;

int lsb(int x) {
    return x&(-x);
}
void update(int x, int t, int v){
    for(int i = t; i < (1e9 + 5); i += lsb(i)){
        time_machine[x][i] += v;
    }    
}

int query(int x, int t){
    int res = 0;
    // remember to make it greater than 0 other than greater or equal to zero
    for(int i = t; i > 0; i -= lsb(i)){
        res += time_machine[x][i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
       
    cin >> qry;
    map<int, int> to;
    int tot = 0;
    forn(i, qry){
        cin >> op >> t >> target;
        if(op == 1 && !to[target]){
            to[target] = ++tot;
        }
        if(op == 1){
            update(to[target], t, 1);
        }
        if(op == 2){
            update(to[target], t, -1);
        }
        if(op == 3){
            cout << query(to[target], t) << endl;
        }
    }
    
    return 0;
}