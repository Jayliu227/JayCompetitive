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

string ins;
int l;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    cin >> l >> ws;
    getline(cin, ins);
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    int init = 1;
    string dir[] = {"-x", "+x", "-y", "+y", "-z", "+z"};
    for(int i = 0; i < ins.size() - 1; i+=3){
        string sub = ins.substr(i, 2);
        if(sub == "No")
            continue;
        else if(sub == "+y"){
            if(init == 0){
                init = 2;
            }else if(init == 1){
                init = 3;
            }else if(init == 2){
                init = 1;
            }else if(init == 3){
                init = 0;
            }else if(init == 4){
                init = 4;
            }else if(init == 5){
                init = 5;
            }
        }else if(sub == "-y"){
            if(init == 0){
                init = 3;
            }else if(init == 1){
                init = 2;
            }else if(init == 2){
                init = 0;
            }else if(init == 3){
                init = 1;
            }else if(init == 4){
                init = 4;
            }else if(init == 5){
                init = 5;
            }
        }else if(sub == "+z"){
            if(init == 0){
                init = 4;
            }else if(init == 1){
                init = 5;
            }else if(init == 2){
                init = 2;
            }else if(init == 3){
                init = 3;
            }else if(init == 4){
                init = 1;
            }else if(init == 5){
                init = 0;
            }
        }else if(sub == "-z"){
            if(init == 0){
                init = 5;
            }else if(init == 1){
                init = 4;
            }else if(init == 2){
                init = 2;
            }else if(init == 3){
                init = 3;
            }else if(init == 4){
                init = 0;
            }else if(init == 5){
                init = 1;
            }
        }        
    }
    
    cout << dir[init] << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}