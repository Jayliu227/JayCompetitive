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

inline int nxt(){ int x; cin >> x; return x; }

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
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
    int k = nxt();
    string ss;
    cin >> ss;
    vi a;
    int zcnt = 0;
    for(int i = 0; i < ss.size(); i++){
        if(ss[i] == '0') zcnt++;
        if(ss[i] == '1'){
            if(zcnt != 0){
                a.pb(-zcnt);                
                zcnt = 0;
            }
            a.pb(1);
        }
    }
    if(zcnt != 0) a.pb(-zcnt);
    int cnt = 0;
    int s = 0, e = 0;
    ll ans = 0;
    
    if(k == 0){
        for(auto i : a) if(i < 0){
            ll t = 1;
            for(int j = 2; j <= -i; j++){
                t += j;
            }
            ans += t;
        }
        cout << ans << endl;
        return 0;
    }
    
    while(e < a.size()){
        while(s < a.size() && a[s] != 1) s++;
        for(int i = e; i < a.size(); i++){
            if(a[i] == 1) cnt++;
            if(cnt == k){
                e = i;
                break;
            }
        }
        if(cnt == k){
            int l = 0, r = 0;
            if(s - 1 >= 0 && a[s - 1] < 0){
                l = -a[s - 1];
            }
            if(e + 1 < a.size() && a[e + 1] < 0){
                r = -a[e + 1];
            }
            ans += (r + 1LL) * (l + 1LL);
            e++;
            s++;
            cnt--;   
        }else{
            break;
        }
    }
    cout << ans << endl;    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}