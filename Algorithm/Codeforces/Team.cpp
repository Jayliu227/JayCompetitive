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
const int MODULO = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n, m;
    cin >> n >> m;

    string res;
    
    int sum = n + m;
    int ones = 0;
    for(int i = 0; i < sum; i++){
        if(res.size() == 0){
            if(n > m){
                res += '0', n--;
            }else{
                res += '1', m--;
                ones++;
            }
        }else if(res[i - 1] == '0'){
            res += '1', m--, ones++;
            if(m < 0){
                cout << -1 << endl;
                return 0;
            }
        }else if(ones == 2){
            res += '0', n--, ones = 0;
            if(n < 0){
                cout << -1 << endl;
                return 0;
            }
        }else{
            if(n > m){
                res += '0', n--, ones = 0;
                if(n < 0){
                    cout << -1 << endl;
                    return 0;
                }
            }else{
                res += '1', m--, ones++;
                if(ones > 2 || m < 0){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << res << endl; 
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}









