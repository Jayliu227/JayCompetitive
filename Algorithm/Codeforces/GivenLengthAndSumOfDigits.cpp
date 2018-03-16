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

int n, s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    cin >> n >> s;
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    if((s == 0 && n != 1)|| s > 9 * n){
        cout << "-1 -1" << endl;
        return 0;
    }
    int ns = s;
    REP(i, 0, n){        
        if(i == 0){
            if(s == 0) {cout << 0; continue;}
            int su = ns - 9 * (n - 1);
            if(su <= 0){
                cout << 1;
                ns -= 1;
            }else{
                cout << su;
                ns -= su;
            }
        }else{
            int su = ns - 9*(n - 1 - i);
            if(su <= 0){
                cout << 0;
            }else{
                cout << su;
                ns -= su;
            }        
        }
    }
    ns = s;
    cout << " ";
    REP(i, 0, n){
        if(ns > 9){
            cout << 9; ns -= 9;
        }else{
            cout << ns; ns = 0;
        }             
    }
    cout << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}