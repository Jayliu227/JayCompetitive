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

int arr[10010];
int n;
int i = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    FILL(arr, 0);
    
    while(cin >> n){
        arr[i++] = n;
        if(i % 2 == 0){
            nth_element(arr, arr + i / 2, arr + i);
            int f = arr[i / 2];
            nth_element(arr, arr + i / 2 - 1, arr + i);
            f += arr[i / 2 - 1];
            cout << (int)floor(f / 2) << endl;
        }else{
            nth_element(arr, arr + i / 2, arr + i);
            cout << (int)arr[i / 2] << endl;
        }    
    }

    return 0;
}