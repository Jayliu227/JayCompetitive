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

int d, dest;
int dir, steps, stepsTaken, x, y;
bool changedLastTime;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int start_s = clock();
//=======CODE GOES HERE============    
    int dx[] = {0,-1,0,1};
    int dy[] = {1,0,-1,0};
    
    while(1){
        cin >> d >> dest;
        if(d == 0 && dest == 0) break;
        
        dir = 0;
        steps = 1;
        stepsTaken = 0;
        changedLastTime = false;        
        x = y = d / 2 + 1;
        for(int i = 1; i < dest; i++){
            stepsTaken++;
            x += dx[dir], y+=dy[dir];
            if(stepsTaken == steps){
                dir = (dir + 1) % 4;
                stepsTaken = 0;
                if(!changedLastTime){
                    changedLastTime = true;
                }else{
                    steps++;
                    changedLastTime = false;
                }
            }
            
        }                
        cout << "Line = " << y << ", column = " << x <<endl; 
    }
    
//=======CODE ENDS HERE============    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    

    return 0;
}