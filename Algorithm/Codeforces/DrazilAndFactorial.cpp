#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
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

/*
    fundemental theorem of arithmetics: every integer has distinct prime factorization.
    so we can simply factor each digit to its max length
*/

string ch[10]={"","","2","3","223","5","35","7","2227","2337"};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int start_s = clock();
    
    int d; cin >> d;
    string str, res;
    cin >> str;
    
    forn(i, str.size()) res += ch[str[i] - '0'];
    sort(ALL(res));
    reverse(ALL(res));
    
    cout << res << endl;
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}