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
const int maxn = (int) 1e6 + 10;

int n;
int drinks[maxn];

int binary(int c){
    int s = 0, e = n - 1;
    while(s < e){
        int mid = (s + e) / 2;
        if(drinks[mid - 1] <= c && drinks[mid] > c){
            return mid;
        }
        if(drinks[mid] > c){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    
    if(s == n - 1 && c >= drinks[s]){
        return s + 1;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    cin >> n;
    forn(i, n){
        int in; cin >> in;
        drinks[i] = in;
    }
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    sort(drinks, drinks + n);

    int m; cin >> m;
    
    forn(i, m){
        int c; cin >> c;
        cout << binary(c) << endl;
    }
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}