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

int m, n;
string m1[maxn], m2[maxn];

void transpose(){
    forn(i, n){
        REP(j, i, n){
            auto temp = m2[i][j];
            m2[i][j] = m2[j][i];
            m2[j][i] = temp;
        }                
    }
}

void reverseColumn(){
    forn(i, n){
        for(int j = 0, k = n -1; j < k; j++, k--){
            auto temp = m2[i][j];
            m2[i][j] = m2[i][k];
            m2[i][k] = temp;
        }
    }    
}

void rotate(){
    transpose();
    reverseColumn();    
}

int find(){
    int num = 0;
    REP(i, 0, m - n + 1){
        REP(j, 0, m - n + 1){
            if(m1[i][j] != m2[0][0]) continue;
            bool ok = true;
            // if we match the first point, we check all things
            for(int p = 0; p < n; p++)
                for(int q = 0; q < n; q++){
                    ok &= m1[i + p][j + q] == m2[p][q];
                }
            if(ok)num++;            
        }
    }    
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(1){
        cin >> m >> n;
        if(m == 0 && n == 0) return 0;
        
        forn(i, m){
            string e; cin >> e;
            m1[i] = e;
        }
        
        forn(i, n){
            string e; cin >> e;
            m2[i] = e;
        }
                
        forn(i, 4){            
            if(i == 0){
                cout << find();
            }else{
                cout << " " << find();
            }
                                                 
            rotate();    
        }   
        cout << endl;
    }    
    
    return 0;
}