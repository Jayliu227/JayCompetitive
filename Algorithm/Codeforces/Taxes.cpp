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

/*
    Lesson: goldbach conjecture -> every even number is sum of two prime numbers
*/

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

bool is_prime(ll n){
    for(int i = 2; i <= (int)sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    ll n; cin >> n;
    if(n == 2){
        cout << 1 << endl;
    }else if(is_prime(n)){
        cout << 1 << endl;
    }else if((n & 1) == 0){
        cout << 2 << endl;
    }else if(is_prime(n - 2)){
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
    }
    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}