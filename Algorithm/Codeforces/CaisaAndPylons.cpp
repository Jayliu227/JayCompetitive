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

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;


const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e4;

int arr[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int start_s = clock();
    
    ll mx = 0;
    ll sum = 0;
    
    RI(x);
    forn(i, x){
        cin >> arr[i];
    }
    
    sum = arr[0];
    mx = arr[0];
    for(int i = 1; i < x; i++){
        if(arr[i] > arr[i - 1]){
            sum += arr[i] - arr[i - 1];
        }else{
            sum -= arr[i - 1] - arr[i];
        }
        mx = max(mx, sum);
    }
    
    cout << mx << endl;
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}