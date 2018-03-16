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

float H, U, D, F, f;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    cin >> H >> U >> D >> F;
    f = U * (F/100.0);
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    int days = 1;
    float cur = 0;
    float prev = U;
    while(1){
        prev = prev < 0 ? 0 : prev;
        cur += prev;               
        cur -= D;
        if(cur >= H && prev > 0){
            cout << "success on day " << days - 1<< endl;
            break;
        }
        if(cur < 0){
            cout << "failure on day " << days << endl;
            break;
        }
        
        prev -= f;        
        days++;   
    }
//=======CODE ENDS HERE============    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}