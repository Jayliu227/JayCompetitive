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
const int maxn = (int) 1e5;

int m, n;
string p, t;
int b[maxn];

void preprocess(){
    int i = 0, j = -1; b[0] = -1;
    while(i < m){
        while(j >= 0 && p[i] != p[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
}

void kmp(){
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 && t[i] != p[j]) j = b[j];
        i++, j++;
        if(j == m){
            cout << (i - m) << endl;
            j = b[j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    getline(cin, p);
    getline(cin, t);
    m = p.size();
    n = t.size();
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    preprocess();
    kmp();
//=======CODE ENDS HERE============    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}