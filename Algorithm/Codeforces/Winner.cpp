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

template<class T> void LOG(T s){
#ifdef LOCAL_COMPILATION
    cout << "DEBUG: " << s << endl;
#endif
}

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    RI(n);

    vector<std::string> winner(n + 1, "");
    vector<long> points(n + 1, 0);

    for(long k = 1; k <= n; k++){
        string name; long addPoints;
        cin >> name >> addPoints;
        winner[k] = name; points[k] = addPoints;
    }

    set<std::string> players;
    for(long k = 1; k <= n; k++){if(players.find(winner[k]) == players.end()){players.insert(winner[k]);}}

    map<string, vector<long> > state;
    set<std::string>::iterator nameIter;

    vector<long> zeroVec(n + 1, 0);
    for(nameIter = players.begin(); nameIter != players.end(); nameIter++){state.insert(std::pair<std::string, std::vector<long> > (*nameIter, zeroVec));}

    for(long k = 1; k <= n; k++){
        for(nameIter = players.begin(); nameIter != players.end(); nameIter++){state[*nameIter][k] = state[*nameIter][k - 1];}
        state[winner[k]][k] += points[k];
    }

    long maxScore = 0;
    for(nameIter = players.begin(); nameIter != players.end(); nameIter++){if(state[*nameIter][n] > maxScore){maxScore = state[*nameIter][n];}}

    std::string finalWinner("");
    for(long k = 1; k <= n; k++){
        if(finalWinner.size() > 0){break;}
        for(nameIter = players.begin(); nameIter != players.end(); nameIter++){
            if(state[*nameIter][k] >= maxScore && state[*nameIter][n] == maxScore){finalWinner = *nameIter; break;}
        }
    }

    cout << finalWinner << endl;
    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}