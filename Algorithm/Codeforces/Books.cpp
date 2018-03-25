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

/*
    use two pointer to find the longest subarray whose sum is smaller or equal to k.
*/

ll b[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int start_s = clock();
    RI(n); RI(t);
    forn(i, n){
        cin >> b[i];
    }
    
    int left = 0, sum = 0, mx = 0;
    for(int right = 0; right < n; right++){
        sum += b[right];
        while(sum > t){
            sum -= b[left++];
        }
    
        mx = max(mx, right - left + 1);
    }
    
    cout << mx << endl;
    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}