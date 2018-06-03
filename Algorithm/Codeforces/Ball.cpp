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

int c[500005];
int maxn, n;

struct node
{
    ll b[3], id;
}ladies[500005];

// Reverse BIT, which stores the information about the suffix instead
// prefix. In this case, it stores the max value of the interval [pos, n - 1]
void change(int pos, int v){
    for(; pos > 0; pos -= pos & -pos){
        chkmax(c[pos], v);
    }
}

int getmax(int pos){
    int mx = -1;
    for(; pos <= maxn; pos += pos & -pos){
        chkmax(mx, c[pos]);
    }
    return mx;
}

bool comp0(node a, node b) {return a.b[0] < b.b[0];}
bool comp1(node a, node b) {return a.b[1] > b.b[1];}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> n;
    forn(i, n) cin >> ladies[i].b[0];
    forn(i, n) cin >> ladies[i].b[1];
    forn(i, n) cin >> ladies[i].b[2];
    sort(ladies, ladies + n, comp0);

    // Discretization
    int rank = 1;
    ladies[0].id = rank;
    for(int i = 0; i < n; i++){
        if(ladies[i].b[0] == ladies[i - 1].b[0]){
            ladies[i].id = rank;
        }else{
            ladies[i].id = ++rank;
        }
    }

    sort(ladies, ladies + n, comp1);
    // Init of BIT
    for1(i, rank + 1) c[i] = -1;

    maxn = rank;
    ll ans = 0;
    int i = 0;
    // Handle those whose discrete ids are the same;
    while(i < n){
        int j;        
        for(j = i; j < n && ladies[j].b[1] == ladies[i].b[1]; j++){
            if(getmax(ladies[j].id + 1) > ladies[j].b[2]) ans++;
        }

        for(j = i; j < n && ladies[j].b[1] == ladies[i].b[1]; j++){
            change(ladies[j].id, ladies[j].b[2]);
        }
        i = j;
    }
    cout << ans << endl;
    return 0;
}


