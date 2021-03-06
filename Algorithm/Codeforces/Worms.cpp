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
const int maxn = (int)1e5;

int piles[maxn];
int a, b;

int binary(int n){
    int i = 0, j = a - 1;
    while(i < j){
        int mid = (i + j) / 2;
        if(piles[mid - 1] < n && piles[mid] >= n){
            return mid + 1;
        } 
        if(piles[mid - 1] >= n)
            j = mid - 1;
        if(piles[mid] < n)
            i = mid + 1;
    }

    return i + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    cin >> a;
    forn(i, a){
        int w; cin >> w;
        piles[i] = w;
    }    
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    REP(i, 1, a){
        piles[i] += piles[i - 1];
    }
    
    int start = 0;

    cin >> b;
    forn(i, b){
        int n; cin >> n;        
        cout << binary(n) << endl;
    }
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}