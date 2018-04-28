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
    int n = nxt();
    string s;
    cin >> s;
    unordered_map<char, int> m;
    if(n % 4 != 0){
        cout << "===" << endl;
        return 0;
    }
    int avg = n / 4;
    for(auto i : s){
        ++m[i];
        if(i != '?' && m[i] > avg){
            cout << "===" << endl;
            return 0;
        }
    }
    forn(i, n){
        if(s[i] == '?'){
            if(m['A'] < avg) s[i] = 'A', m['A']++;
            else if(m['C'] < avg) s[i] = 'C', m['C']++;
            else if(m['G'] < avg) s[i] = 'G', m['G']++;
            else if(m['T'] < avg) s[i] = 'T', m['T']++;
            else{
                cout << "===" << endl;
                return 0;
            }
        }        
    }
    cout << s << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}