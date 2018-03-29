#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define RI(x) int (x); cin >> (x)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

template<class T> void LOG(T s){
#ifdef LOCAL_COMPILATION
    cout << "DEBUG: " << s << endl;
#endif
}

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;


const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e4;

int dp[101][8];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    string in; cin >> in;
    
    if(in.size() > 0){
    for(int i = 0; i < in.size(); i++){
        if((in[i] - '0') % 8 == 0){
            cout << "YES" << endl;
            cout << (in[i] - '0') << endl;
            return 0;
        }
    }}
    
    if(in.size() > 1){
    for(int i = 0; i < in.size() - 1; i++){
        for(int j = i + 1; j < in.size(); j++){
            int v = (in[i] - '0') * 10 + (in[j] - '0');
            if(v % 8 == 0){
                cout << "YES" << endl;
                cout << v << endl;
                return 0;
            }
        }
    }}
    
    if(in.size() > 2){
    for(int i = 0; i < in.size() - 2; i++){
        for(int j = i + 1; j < in.size() - 1; j++){
            for(int k = j + 1; k < in.size(); k++){
                int v = (in[i] - '0') * 100 + (in[j] - '0') * 10 + (in[k] - '0');
                if(v % 8 == 0){
                    cout << "YES" << endl;
                    cout << v << endl;
                    return 0;
                }
            }
        }
    }}
    
    cout << "NO" << endl;
    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}













