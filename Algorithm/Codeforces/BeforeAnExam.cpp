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

int d, sum;
int low[31];
int high[31];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> d >> sum;
    int lowSum = 0, highSum = 0;
    int l, h;
    forn(i, d){
        cin >> l >> h;
        lowSum += l, highSum += h;
        low[i] = l; high[i] = h;
    }        
    
    if(sum < lowSum || sum > highSum){
        cout << "NO" << endl;
        return 0;
    }
    
    int spls = sum - lowSum;
    
    for(int i = 0; i < d; i++){
        if(spls == 0)
            break;
        int more = high[i] - low[i];
        if(spls >= more){
            low[i] = high[i], spls -= more;
        }else{
            low[i] += spls, spls = 0;
        }
    }
    
    cout << "YES" << endl;
    
    forn(i, d){
        if(i == 0){
            cout << low[i];
        }else{
            cout << " " << low[i];
        }
    }
    
    cout << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}











