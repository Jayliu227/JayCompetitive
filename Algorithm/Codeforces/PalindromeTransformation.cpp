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

template<class T> inline void LOG(T s){
#ifdef LOCAL_COMPILATION
    cout << "DEBUG: " << s << endl;
#endif
}

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
    int p = nxt();
    string s;
    cin >> s;
    function<int(char, char)> dist = [&](char a, char b){
        if(a == b) return 0;
        else if(a < b){
            return min(b - a, 'z' - b + a - 'a' + 1);
        }else{
            return min(a - b, 'z' - a + b - 'a' + 1);
        }
    };
    
    p--;
    
    if(p >= s.size() / 2) p = s.size() - p - 1;
    vector<int> change(n / 2);

    ll ans = 0;
    int l = -1, r = -1;
    for(int i = 0; i < s.size() / 2; i++){
        int d = dist(s[i], s[n - 1 - i]);
        //cerr << s[i] << " " << s[n - 1 - i] << " " << d << endl;
        if(d != 0){
            ans += d;
            if(l == -1) l = i;
            if(r == -1) r = i;
            else if(r != -1) r = max(r, i);
        }
    }
    //cerr << ans << endl;
    //cerr << l << " " << r << endl;
    int ld = abs(p - l);
    int rd = abs(p - r);
    if(l == -1 && r == -1) ld = 0, rd = 0;
    if(l <= p && r <= p || l >= p && r >= p)
        ans += max(ld, rd);
    else        
        ans += min(ld, rd) * 2 + max(ld, rd);
    
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}