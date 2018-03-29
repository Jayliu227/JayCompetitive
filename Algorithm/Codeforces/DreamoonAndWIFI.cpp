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

/*
    Andre Nicolas:
        c(n, k) = (n/k) c(n - 1, k - 1)
*/

int c(int n, int k){    
    if(k == 0){
        return 1;
    }
    if(k > n / 2){
        return c(n, n - k);
    }
    return n * c(n - 1, k - 1) / k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    string s1, s2;
    cin >> s1; cin >> s2;
    int ps = 0, qs = 0, ms = 0;
    for(int i = 0; i < s1.size(); i++){
        ps += s1[i] == '+';
        ps -= s2[i] == '+';
        ms += s1[i] == '-';
        ms -= s2[i] == '-';
        
        qs += s2[i] == '?';
    }     

    if(ms < 0 || ps < 0){
        cout << 0 << endl;
        return 0;
    }
    
    int res = pow(2, qs);
    
    cout << c(qs, ps) / (double) res << endl;
    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}





