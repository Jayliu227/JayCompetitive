#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define endl '\n'

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;


const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e4;

int TC, n, l, v;
char c;
unordered_map<char, float> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(3);
//=======GET INPUT HERE============
    cin >> TC;
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    while(TC--){
        cin >> n;
        forn(i, n){
            cin >> c >> v;
            m[c] = v/100.0;
        }
        cin >> l;
        float result = 0;
        forn(i, l){
            string ns;
            getline(cin, ns);
            for(auto ch : ns){
                result += m[ch];
            }
        }        
        m.clear();
        cout << result << "$" << endl;
    }
//=======CODE ENDS HERE============    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}