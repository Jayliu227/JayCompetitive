#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'

using namespace std;

inline int nxt(){ int x; cin >> x; return x; }

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    string s;
    cin >> s;
    int mid = 0;
    vector<pair<int,int>> weights;
    int n = s.size();
    forn(i, n){
        if(s[i] == '^'){
            mid = i;
        }else if(s[i] != '='){
            weights.emplace_back(s[i] - '0', i);
        }
    }
    ll left = 0, right = 0;
    for(int i = 0; i < weights.size(); i++){
        if(weights[i].se > mid){
            right += (ll)weights[i].fi * (weights[i].se - mid);
        }else{
            left += (ll)weights[i].fi * (mid - weights[i].se);
        }
    }
    if(left == right){
        cout << "balance" << endl;
    }else if(left < right){
        cout << "right" << endl;
    }else{
        cout << "left" << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}