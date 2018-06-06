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
const int maxn = (int) 1e5 + 5;
const int K = 26;

int n, m, k;
int data[6][maxn];
int stables[6][maxn][K];
int LOG[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    cin >> n >> m >> k;
    forn(i, n){
        forn(j, m){
            cin >> data[j][i];
        }
    }    

    // init;
    FILL(stables, -1);
    for(int st = 0; st < m; st++){
        for(int i = 0; i < n; i++){
            stables[st][i][0] = data[st][i];
        }
    }

    for(int st = 0; st < m; st++){
        for(int j = 1; j < K; j++){
            for(int i = 0; i + (1 << j) <= n; i++){
                // since both segments are of length 2^(j - 1) (originally 2^j), thus we need to make it (1 << (j - 1))
                stables[st][i][j] = max(stables[st][i][j - 1], stables[st][i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    LOG[1] = 0;
    for(int i = 2; i <= maxn; i++) LOG[i] = LOG[i / 2] + 1;

    int len = -1;
    int l = 0, r = 0;
    vector<int> res(m, 0);
    while(r < n){
        vector<int> partial;
        for(int st = 0; st < m; st++){
            // find max in range l, r and update it
            int j = LOG[r - l + 1];
            partial.pb(max(stables[st][l][j], stables[st][r - (1 << j) + 1][j]));           
            
        }       
        int s = accumulate(ALL(partial), 0);
        if(s <= k){
            if(r - l + 1 > len){
                len = r - l + 1;
                res = partial;
            }
            r++;
        }else{
            l++;
            if(l > r){
                r++;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}


